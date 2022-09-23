/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render_minimap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:13:59 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:04:29 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include <math.h>

static inline uint8_t	blend(uint8_t dst, uint8_t src, uint8_t opacity)
{
	const uint16_t	scaled_dst = (uint16_t)dst * (255 - (uint16_t)opacity);
	const uint16_t	scaled_src = (uint16_t)src * (uint16_t)opacity;
	const uint16_t	scaled_result = scaled_dst + scaled_src;

	return ((uint8_t)(scaled_result / 255));
}

static void	set_tile_color(
				t_game *self,
				size_t tile_x,
				size_t tile_y,
				t_rgba *rgba)
{
	uint8_t			opacity;
	const size_t	index = tile_y * self->width + tile_x;

	if (tile_x >= self->width || tile_y >= self->height
		|| self->tiles[index] == C3D_TILE_VOID
		|| self->tiles[index] == C3D_TILE_WALL)
		return ;
	if (self->tiles[index] == C3D_TILE_LINE
		|| self->tiles[index] == C3D_TILE_LINE_OPEN)
		opacity = 200;
	else if (self->tiles[index] == C3D_TILE_TRACK
		|| self->tiles[index] == C3D_TILE_RLINE)
		opacity = 100;
	else if (self->tiles[index] == C3D_TILE_FLOOR)
		opacity = 50;
	else
		opacity = 0;
	rgba->red = blend(rgba->red, 0xff, opacity);
	rgba->green = blend(rgba->green, 0xff, opacity);
	rgba->blue = blend(rgba->blue, 0xff, opacity);
}

static void	set_minimap_color(
				t_game *self,
				int32_t map_x,
				int32_t map_y,
				t_rgba *rgba)
{
	const float	a = PI / 2.0f + self->player.angle;
	const float	local_x = (float)map_x / (float)C3D_MINIMAP_SCALE;
	const float	local_y = (float)map_y / (float)C3D_MINIMAP_SCALE;
	float		x;
	float		y;

	x = local_x * cosf(a) - local_y * sinf(a);
	y = local_x * sinf(a) + local_y * cosf(a);
	x += self->player.pos.x;
	y += self->player.pos.y;
	set_tile_color(self, (size_t)x, (size_t)y, rgba);
}

static void	put_mini_car(t_game *self, uint32_t x, uint32_t y)
{
	uint32_t	i;
	uint32_t	j;
	t_rgb		c;

	j = 0;
	while (j < self->mini_car_texture.height)
	{
		i = 0;
		while (i < self->mini_car_texture.width)
		{
			c = self->mini_car_texture.data[j
				* self->mini_car_texture.width + i].rgb;
			if (c.red != 255 || c.green != 0 || c.blue != 255)
				self->canvas.data[self->canvas.width * (y + j
						- self->mini_car_texture.height / 2) + x + i
					- self->mini_car_texture.width / 2].rgb = c;
			i++;
		}
		j++;
	}
}

void	c3d_game_render_minimap(t_game *self)
{
	const int32_t	_x = C3D_WIDTH - C3D_MINIMAP_OFFSET;
	const int32_t	_y = C3D_HEIGHT - C3D_MINIMAP_OFFSET;
	int32_t			x;
	int32_t			y;

	y = -1 - C3D_MINIMAP_RADIUS;
	while (++y < C3D_MINIMAP_RADIUS)
	{
		x = -1 - C3D_MINIMAP_RADIUS;
		while (++x < C3D_MINIMAP_RADIUS)
		{
			if (x * x + y * y >= C3D_MINIMAP_RADIUS * C3D_MINIMAP_RADIUS)
				continue ;
			set_minimap_color(self, x, y,
				&self->canvas.data[self->canvas.width * (_y + y) + _x + x]);
		}
	}
	put_mini_car(self, _x, _y);
}
