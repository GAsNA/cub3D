/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:31:44 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/11 18:20:54 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "libft.h"

# define SIZE 4

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	ft_open_window(char **map, int x, int y);

#endif
