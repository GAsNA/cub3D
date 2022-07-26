/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_is_enclosed.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:10:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 13:43:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static bool	check_enclosed_from(t_map_parser *self, uint32_t x, uint32_t y)
{
	if (y >= self->lines.len || x >= self->lines.data[y].len
		|| self->lines.data[y].line[x] == C3D_TILE_VOID)
		return (false);
	if (self->lines.data[y].line[x] == C3D_TILE_TRACK
		|| self->lines.data[y].line[x] == C3D_TILE_WALL)
		return (true);
	self->lines.data[y].line[x] = C3D_TILE_TRACK;
	return (check_enclosed_from(self, x + 1, y)
		&& check_enclosed_from(self, x - 1, y)
		&& check_enclosed_from(self, x, y - 1)
		&& check_enclosed_from(self, x, y + 1));
}

bool	c3d_map_parser_is_enclosed(t_map_parser *self)
{
	if (check_enclosed_from(
			self,
			self->map->player.x,
			self->map->player.y))
		return (true);
	else
	{
		c3d_map_parser_push_error(self, "the map is not perfectly enclosed!");
		return (false);
	}
}
