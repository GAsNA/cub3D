/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:36:13 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 20:02:24 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static void	set_player_spawn_point(t_map_parser *self, t_dir direction)
{
	if (self->map->player.dir != 0)
	{
		c3d_map_parser_push_error(self,
			"line {ulong}: player spawn already defined at ({u32}, {u32})",
			self->line, self->map->player.x, self->map->player.y);
		return ;
	}
	self->map->player.dir = direction;
	self->map->player.x = self->walls.len;
	self->map->player.y = self->lines.len;
	self->walls.data[self->walls.len++] = false;
}

static void	new_line(t_map_parser *self)
{
	ft_vec_reserve((t_vec *)&self->lines, 1, sizeof(bool));
	self->lines.data[self->lines.len].line
		= ft_alloc_array(self->walls.len, sizeof(bool));
	ft_mem_copy(
		self->lines.data[self->lines.len].line,
		self->walls.data,
		self->walls.len);
	self->lines.data[self->lines.len].len = self->walls.len;
	self->walls.len = 0;
	self->lines.len++;
}

void	c3d_map_parser_map(t_map_parser *self)
{
	uint8_t	b;

	while (ft_reader_get(&self->reader, 0, &b))
	{
		ft_vec_reserve((t_vec *)&self->walls, 1, sizeof(bool));
		if (b == ' ' || b == '0')
			self->walls.data[self->walls.len++] = false;
		else if (b == '1')
			self->walls.data[self->walls.len++] = true;
		else if (b == 'N')
			set_player_spawn_point(self, C3D_DIR_NORTH);
		else if (b == 'E')
			set_player_spawn_point(self, C3D_DIR_EAST);
		else if (b == 'S')
			set_player_spawn_point(self, C3D_DIR_SOUTH);
		else if (b == 'W')
			set_player_spawn_point(self, C3D_DIR_WEST);
		else if (b == '\n')
			new_line(self);
		else
			c3d_map_parser_push_error(self,
				"line {ulong}: character '{c?}' not expected in the map",
				self->line, b);
		ft_reader_consume(&self->reader, 1);
	}
}
