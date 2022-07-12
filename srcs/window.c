/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:16:46 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/11 21:39:57 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	draw_map(t_vars *vars, char **map, int xp, int xy)
{
	int	i;
	int	j;
	int 	color;

	color = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == xp && j == yp)
				color = 0x00FF0000;
			else if (map[i][j] == '1' || map[i][j] == '2' || map[i][j] == '3')
				color = 0x00000000;
			else
				color = 0x00FFFFFF;
			draw_square(&img, j * SIZE, )
		}
	}
}

void	ft_open_window(char **map, int x, int y, int xp, int yp)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x * SIZE, y * SIZE, "Cub3D");
	draw_map(&vars, map, xp, yp);
}
