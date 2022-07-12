/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:16:46 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 18:31:07 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	get_all(t_all *all, t_vars *vars, t_img *img, t_game *game)
{
	all->vars = vars;
	all->img = img;
	all->game = game;
}

void	ft_open_window(t_game game)
{
	t_vars	vars;
	t_img	img;
	t_all	all;

	get_all(&all, &vars, &img, &game);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, game.x * SIZE, game.y * SIZE, "Cub3D");
	img.img = mlx_new_image(vars.mlx, game.x * SIZE, game.y * SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_map(&img, game.map, game.xp, game.yp);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, KEYPRESS, KEYPRESSMASK, key_hook, &all);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_win, &all);
	mlx_loop(vars.mlx);
}
