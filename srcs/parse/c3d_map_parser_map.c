/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:36:13 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:15:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

#define MAX_ERRORS 32

static bool	set_player_spawn_point(t_map_parser *self, t_dir direction)
{
	if (self->map->player.dir != 0)
		return (
			c3d_map_parser_push_error(self,
				"line {ulong}: player spawn already defined at ({u32}, {u32})",
				self->line, self->map->player.x, self->map->player.y),
			false);
	self->map->player.dir = direction;
	self->map->player.x = self->walls.len;
	self->map->player.y = self->lines.len;
	self->walls.data[self->walls.len++] = C3D_TILE_FLOOR;
	return (true);
}

static void	new_line(t_map_parser *self)
{
	if (self->walls.len == 0)
	{
		if (!c3d_map_parser_is_end_of_file(self))
			c3d_map_parser_push_error(
				self, "line {ulong}: empty line found while parsing the map",
				self->line++);
		return ;
	}
	ft_vec_reserve((t_vec *)&self->lines, 1, sizeof(struct s_map_parser_line));
	if (self->walls.len)
	{
		self->lines.data[self->lines.len].line
			= ft_alloc_array(self->walls.len, sizeof(uint8_t));
		ft_mem_copy(
			self->lines.data[self->lines.len].line,
			self->walls.data,
			self->walls.len);
	}
	else
		self->lines.data[self->lines.len].line = NULL;
	self->lines.data[self->lines.len].len = self->walls.len;
	self->walls.len = 0;
	self->lines.len++;
	self->line++;
}

static bool	absorbe_char2(t_map_parser *self, uint8_t b)
{
	if (b == ' ')
		self->walls.data[self->walls.len++] = C3D_TILE_VOID;
	else if (b == '0')
		self->walls.data[self->walls.len++] = C3D_TILE_FLOOR;
	else if (b == '1')
		self->walls.data[self->walls.len++] = C3D_TILE_WALL;
	else if (b == 'N')
		return (set_player_spawn_point(self, C3D_DIR_NORTH));
	else if (b == 'E')
		return (set_player_spawn_point(self, C3D_DIR_EAST));
	else if (b == 'S')
		return (set_player_spawn_point(self, C3D_DIR_SOUTH));
	else if (b == 'W')
		return (set_player_spawn_point(self, C3D_DIR_WEST));
	else if (b == '#')
		self->walls.data[self->walls.len++] = C3D_TILE_LINE_OPEN;
	else if (b == '*')
		self->walls.data[self->walls.len++] = C3D_TILE_RLINE_OUTSIDE;
	else if (b == '\n')
		new_line(self);
	else
		return (false);
	return (true);
}

static bool	absorbe_char(t_map_parser *self, uint8_t b)
{
	ft_vec_reserve((t_vec *)&self->walls, 1, sizeof(uint8_t));
	if (!absorbe_char2(self, b))
	{
		self->walls.data[self->walls.len++] = C3D_TILE_FLOOR;
		return (c3d_map_parser_push_error(self,
				"line {ulong}: character '{c?}' not expected in the map",
				self->line, b), false);
	}
	return (true);
}

bool	c3d_map_parser_map(t_map_parser *self)
{
	uint8_t	b;
	bool	any_error;

	any_error = false;
	while (self->errors.len < MAX_ERRORS && ft_reader_get(&self->reader, 0, &b))
	{
		any_error |= absorbe_char(self, b);
		ft_reader_consume(&self->reader, 1);
	}
	new_line(self);
	if (self->errors.len >= MAX_ERRORS)
		return (
			c3d_map_parser_push_error(self, "too many errors; fix your map!"),
			false);
	if (self->map->player.dir == 0)
		return (c3d_map_parser_push_error(self,
				"no spawn point defined for the player"), false);
	return (any_error);
}
