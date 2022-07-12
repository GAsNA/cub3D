/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:16:46 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 17:17:27 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_square(t_img *img, int j, int i, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SIZE)
	{
		my_mlx_pixel_put(img, j + x, i + y, color);
		x++;
		if (x == SIZE)
		{
			y++;
			x = 0;
		}
	}
}

void	draw_map(t_img *img, char map[20][36], int xp, int yp)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	color = 0;
	while (++i < 20)
	{
		j = -1;
		while (++j < 36)
		{
			if (i == xp && j == yp)
				color = 0x00FF0000;
			else if (map[i][j] == '1' || map[i][j] == '2' || map[i][j] == '3')
				color = 0x00000000;
			else if (map[i][j] == '0')
				color = 0x00FFFFFF;
			draw_square(img, j * SIZE, i * SIZE, color);
		}
	}
}

void	ft_open_window(char map[20][36], int x, int y, int xp, int yp)
{
	t_vars	vars;
	t_img	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x * SIZE, y * SIZE, "Cub3D");
	img.img = mlx_new_image(vars.mlx, x * SIZE, y * SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_map(&img, map, xp, yp);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
