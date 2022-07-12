/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:42:24 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 17:42:51 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, int j, int i, int color)
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

