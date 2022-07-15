/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:31:44 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/14 18:33:51 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "../minilibx/mlx.h"

# define SIZE 16

/* Colors */
# define GREEN 0x0000561B
# define RED 0x00FF0000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

/* Keycode */
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

/* X11 events */
# define KEYPRESS 2
# define DESTROYNOTIFY 33

/* X11 masks */
# define STRUCTURENOTIFYMASK 1L<<17
# define KEYPRESSMASK 1L<<0

/* Structures */
typedef struct s_vars	t_vars;
typedef struct s_img	t_img;
typedef struct s_game	t_game;
typedef struct s_all	t_all;

struct s_vars
{
	void	*mlx;
	void	*win;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
};

struct s_game
{
	char	map[20][36];
	int		x;
	int		y;
	int		xp;
	int		yp;
};

struct s_all
{
	t_vars	*vars;
	t_img	*img;
	t_game	*game;
};

/* window.c */
void	ft_open_window(t_game game);

/* draw.c */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_line_horizontal(t_img *img, int j, int i, int color);
void	draw_line_vertical(t_img *img, int j, int i, int color);
void	draw_square(t_img *img, int j, int i, int color);
void	draw_map(t_img *img, char map[20][36], int xp, int yp);

/* actions_win.c */
int		close_win(t_all *all);
int		key_hook(int keycode, t_all *all);

/* moving.c */
void	go_up(t_all *all);
void	go_down(t_all *all);
void	go_left(t_all *all);
void	go_right(t_all *all);

/* free.c */
void	all_free(t_all *all);

#endif
