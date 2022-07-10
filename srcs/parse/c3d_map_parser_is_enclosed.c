/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_is_enclosed.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:10:38 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 22:45:39 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static bool	check_enclosed_from(t_map_parser *self, uint32_t x, uint32_t y);

inline static uint64_t	encode(uint32_t x, uint32_t y)
{
	return ((uint64_t)x | (uint64_t)y << 32);
}

static void	check_position(
				t_map_parser *self,
				bool *ret,
				uint64_t check,
				uint64_t origin)
{
	const uint32_t	x = (uint32_t)check;
	const uint32_t	y = (uint32_t)(check >> 32);
	const uint32_t	origin_x = (uint32_t)origin;
	const uint32_t	origin_y = (uint32_t)(origin >> 32);

	if (y >= self->lines.len || x >= self->lines.data[y].len)
	{
		if (*ret)
		{
			c3d_map_parser_push_error(
				self,
				"map leak at ({u32}, {u32})",
				origin_x, origin_y);
			*ret = false;
		}
	}
	else
		*ret &= check_enclosed_from(self, x, y);
}

static bool	check_enclosed_from(t_map_parser *self, uint32_t x, uint32_t y)
{
	bool	ret;

	if (self->lines.data[y].line[x] != 0)
		return (true);
	self->lines.data[y].line[x] = 2;
	ret = true;
	check_position(self, &ret,encode(x + 1, y), encode(x, y));
	check_position(self, &ret, encode(x - 1, y), encode(x, y));
	check_position(self, &ret, encode(x, y - 1), encode(x, y));
	check_position(self, &ret, encode(x, y + 1), encode(x, y));
	return (ret);
}

bool	c3d_map_parser_is_enclosed(t_map_parser *self)
{
	return (
		check_enclosed_from(
			self,
			self->map->player.x,
			self->map->player.y));
}
