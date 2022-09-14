/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render_car.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:02 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/14 15:41:19 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include <stddef.h>
#include <math.h>
#include <unistd.h>

#define WHEEL_X 400
#define WHEEL_Y 550
#define DISP_X 150.0f
#define DISP_Y 80.0f

static inline void	put_pixel(t_img *canvas, t_rgb color, size_t x, size_t y)
{
	if (x >= canvas->width || y >= canvas->height
		|| (color.red == 255 && color.green == 0 && color.blue == 255))
		return ;
	canvas->data[y * canvas->width + x].rgb = color;
}

static void render_background(t_game *game)
{
	ssize_t			i;
	ssize_t			j;
	const ssize_t	offset_x = (ssize_t)(game->player.look.x * DISP_X);
	const ssize_t	offset_y = (ssize_t)(game->player.look.y * DISP_Y);

	i = 0;
	while (i < game->car_background_texture.height * 6)
	{
		j = 0;
		while (j < game->car_background_texture.width * 6)
		{
			put_pixel(&game->canvas, game->car_background_texture.data[(i / 6) * game->car_background_texture.width + j / 6].rgb, j - offset_x - 510, i - offset_y - 520);
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

	i = 0;
	while (i < C3D_WHEEL_SIZE)
	{
		j = 0;
		while (j < C3D_WHEEL_SIZE)
		{
			put_pixel(&game->canvas, get_rotated_color(&game->car_wheel_texture, (float)j, (float)i, -game->player.delta_angle * C3D_WHEEL_FACTOR), j + WHEEL_X - C3D_WHEEL_SIZE / 2 - (size_t)(game->player.look.x * DISP_X), i + WHEEL_Y - C3D_WHEEL_SIZE / 2 - (size_t)(game->player.look.y * DISP_Y));
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
