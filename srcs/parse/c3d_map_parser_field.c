/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:09:06 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 20:09:17 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static t_str	parse_ident(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;
	t_str	str;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != ' ' && b == '\t')
		i++;
	str = (t_str){(void *)self->reader.data + self->reader.con, i};
	ft_reader_consume(&self->reader, i);
	return (str);
}

bool	c3d_map_parser_field(t_map_parser *self)
{
	uint8_t	byte;
	t_str	id;

	if (!ft_reader_get(&self->reader, 0, &byte) || byte == ' ' || byte == '\t')
		return (false);
	id = parse_ident(self);
	if (id.len == 2 && id.data[0] == 'N' && id.data[1] == 'O')
		c3d_map_parser_filename(self, id, &self->map->north_texture);
	else if (id.len == 2 && id.data[0] == 'E' && id.data[1] == 'A')
		c3d_map_parser_filename(self, id, &self->map->east_texture);
	else if (id.len == 2 && id.data[0] == 'S' && id.data[1] == 'O')
		c3d_map_parser_filename(self, id, &self->map->south_texture);
	else if (id.len == 2 && id.data[0] == 'W' && id.data[1] == 'E')
		c3d_map_parser_filename(self, id, &self->map->west_texture);
	else if (id.len == 1 && id.data[0] == 'C')
		c3d_map_parser_color(self, id, &self->map->ceiling_color);
	else if (id.len == 1 && id.data[0] == 'F')
		c3d_map_parser_color(self, id, &self->map->floor_color);
	else
		return (
			c3d_map_parser_push_error(
				self, "line {ulong}: '{str}' is not a known identifier",
				self->line, id), c3d_map_parser_skip_line(self), true);
	return (true);
}
