/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_is_enclosed.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:10:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 23:06:03 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static bool	check_enclosed_from(t_map_parser *self, uint32_t x, uint32_t y);

static bool	check_position(t_map_parser *self, uint32_t x, uint32_t y)
{
	if (y >= self->lines.len || x >= self->lines.data[y].len)
		return (false);
	else
		return (check_enclosed_from(self, x, y), true);
}

static bool	check_enclosed_from(t_map_parser *self, uint32_t x, uint32_t y)
{
	if (self->lines.data[y].line[x] != 0)
		return (true);
	self->lines.data[y].line[x] = 2;
	return (check_position(self, x + 1, y)
		&& check_position(self, x - 1, y)
		&& check_position(self, x, y - 1)
		&& check_position(self, x, y + 1));
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
