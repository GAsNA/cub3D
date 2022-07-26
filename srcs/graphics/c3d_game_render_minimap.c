/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render_minimap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:13:59 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 17:51:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include <math.h>

static inline uint8_t	blend(uint8_t dst, uint8_t src, uint8_t opacity)
{
	const uint16_t	scaled_dst = (uint16_t)dst * (255 - (uint16_t)opacity);
	const uint16_t	scaled_src = (uint16_t)src * (uint16_t)opacity;
	const uint16_t	scaled_rslt = scaled_dst + scaled_src;

	return ((uint8_t)(scaled_rslt / 255));
}

static void set_tile_color(t_game *self, size_t tile_x, size_t tile_y, t_rgba *rgba)
{
	uint8_t			opacity;
	const size_t	index = tile_y * self->width + tile_x;

	if (tile_x >= self->width || tile_y >= self->height
		|| self->tiles[index] == C3D_TILE_VOID
		|| self->tiles[index] == C3D_TILE_WALL)
		return ;
	if (self->tiles[index] == C3D_TILE_TRACK)
		opacity = 100;
	else if (self->tiles[index] == C3D_TILE_FLOOR)
		opacity = 50;
	else
		opacity = 0;
	rgba->red = blend(rgba->red, 0xff, opacity);
	rgba->green = blend(rgba->green, 0xff, opacity);
	rgba->blue = blend(rgba->blue, 0xff, opacity);
}

static void	set_minimap_color(t_game *self, int32_t x, int32_t y, t_rgba *rgba)
{
	// const size_t	tile_x = (size_t)(x / C3D_MINIMAP_SCALE)
	// 	+ (size_t)(self->player.pos.x + self->width / 2.0);
	// const size_t	tile_y = (size_t)(y / C3D_MINIMAP_SCALE)
	// 	+ (size_t)(self->height / 2.0 - self->player.pos.y);
	float	pos_x;
	float	pos_y;

	pos_x = (float)x / (float)C3D_MINIMAP_SCALE + self->player.pos.x + (float)self->width / 2.0;
	pos_y = (float)y / (float)C3D_MINIMAP_SCALE - self->player.pos.y + (float)self->height / 2.0;

	pos_x = pos_x * cosf(self->player.angle) + pos_y * -sinf(self->player.angle);
	pos_y = pos_x * sinf(self->player.angle) + pos_y * cosf(self->player.angle);

	set_tile_color(self, (size_t)pos_x, (size_t)pos_y, rgba);
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
	self->canvas.data[self->canvas.width * _y + _x]
		= (t_rgba){{{0, 0, 255}}, 0};
	self->canvas.data[self->canvas.width * (_y + 1) + _x]
		= (t_rgba){{{0, 0, 255}}, 0};
}
