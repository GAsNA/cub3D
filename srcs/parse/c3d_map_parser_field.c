/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:09:06 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:59:35 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static bool	parse_ident(t_map_parser *self, t_str *result)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && 'A' <= b && b <= 'Z')
		i++;
	if (i == 0 || (b != ' ' && b != '\n' && b != '\t'))
		return (false);
	*result = (t_str){(void *)self->reader.data + self->reader.con, i};
	return (ft_reader_consume(&self->reader, i), true);
}

static void	parse_value(t_map_parser *self, t_str id)
{
	if (id.len == 2 && id.data[0] == 'N' && id.data[1] == 'O')
		c3d_map_parser_filename(self, id, &self->map->north_texture);
	else if (id.len == 2 && id.data[0] == 'E' && id.data[1] == 'A')
		c3d_map_parser_filename(self, id, &self->map->east_texture);
	else if (id.len == 2 && id.data[0] == 'S' && id.data[1] == 'O')
		c3d_map_parser_filename(self, id, &self->map->south_texture);
	else if (id.len == 2 && id.data[0] == 'W' && id.data[1] == 'E')
		c3d_map_parser_filename(self, id, &self->map->west_texture);
	else if (id.len == 1 && id.data[0] == 'C')
		c3d_map_parser_color(
			self, id,
			&self->map->ceiling_color, &self->has_ceiling_color);
	else if (id.len == 1 && id.data[0] == 'F')
		c3d_map_parser_color(
			self, id,
			&self->map->floor_color, &self->has_floor_color);
	else
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str}' is not a known identifier",
			self->line, id);
		c3d_map_parser_skip_line(self);
	}
}

bool	c3d_map_parser_field(t_map_parser *self)
{
	t_str	id;

	if (!parse_ident(self, &id))
		return (false);
	parse_value(self, id);
	return (true);
}
