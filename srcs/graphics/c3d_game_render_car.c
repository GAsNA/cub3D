/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render_car.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:02 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/14 14:05:26 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include <stddef.h>
#include <math.h>

#define WHEEL_X 400
#define WHEEL_Y 550

static void render_background(t_game *game)
{
	size_t	i;
	size_t	j;
	t_rgb	color;

	i = 0;
	while (i < game->canvas.height)
	{
		j = 0;
		while (j < game->canvas.width)
		{
			color = game->car_background_texture.data[
				(i / 6 + 2) * game->car_background_texture.width + j / 6 + 18].rgb;
			if (color.red != 255 || color.green != 0 || color.blue != 255)
				game->canvas.data[i * game->canvas.width + j].rgb = color;
			j++;
		}
		i++;
	}
}

static t_rgb	get_rotated_color(t_img *img, float x, float y, float a)
{
	const float	_x = x / (float)C3D_WHEEL_SIZE - 0.5f;
	const float _y = y / (float)C3D_WHEEL_SIZE - 0.5f;
	size_t	final_x;
	size_t	final_y;

	a += PI / 2.0f;
	x = _x * cosf(a) - _y * sinf(a);
	y = _x * sinf(a) + _y * cosf(a);
	x += 0.5f;
	y += 0.5f;
	x *= (float)img->width;
	y *= (float)img->height;
	final_x = (size_t)x;
	final_y = (size_t)y;
	if (x <= 0 || y <= 0 || final_x >= img->width || final_y >= img->height)
		return ((t_rgb){255, 0, 255});
	return (img->data[final_y * img->width + final_x].rgb);
}

static void	render_wheel(t_game *game)
{
	size_t	i;
	size_t	j;
	t_rgb	color;

	i = 0;
	while (i < C3D_WHEEL_SIZE && i + WHEEL_Y - C3D_WHEEL_SIZE / 2 < C3D_HEIGHT)
	{
		j = 0;
		while (j < C3D_WHEEL_SIZE)
		{
			color = get_rotated_color(&game->car_wheel_texture, (float)i,
				(float)j, game->player.delta_angle * C3D_WHEEL_FACTOR);
			if (color.red != 255 || color.green != 0 || color.blue != 255)
				game->canvas.data[(i + WHEEL_Y - C3D_WHEEL_SIZE / 2) * game->canvas.width + j + WHEEL_X - C3D_WHEEL_SIZE / 2].rgb = color;
			j++;
		}
		i++;
	}
}

void	c3d_game_render_car(t_game *game)
{
	render_background(game);
	render_wheel(game);
}
