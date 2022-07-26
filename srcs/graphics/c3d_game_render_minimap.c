/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render_minimap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:13:59 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 15:14:34 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include <unistd.h>

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

static void	set_minimap_color(t_game *self, size_t x, size_t y, t_rgba *rgba)
{
	const size_t	tile_x = x / C3D_MINIMAP_SCALE
		+ (size_t)(self->player.pos.x + self->width / 2.0);
	const size_t	tile_y = y / C3D_MINIMAP_SCALE
		+ (size_t)(self->player.pos.y + self->height / 2.0);

	set_tile_color(self, tile_x, tile_y, rgba);
}

void	c3d_game_render_minimap(t_game *self)
{
	const size_t	_x = C3D_WIDTH - C3D_MINIMAP_OFFSET;
	const size_t	_y = C3D_HEIGHT - C3D_MINIMAP_OFFSET;
	size_t			x;
	size_t			y;

	y = (size_t)-1 - C3D_MINIMAP_RADIUS;
	while ((ssize_t)++y < (ssize_t)C3D_MINIMAP_RADIUS)
	{
		x = (size_t) - 1 - C3D_MINIMAP_RADIUS;
		while ((ssize_t)++x < (ssize_t)C3D_MINIMAP_RADIUS)
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
