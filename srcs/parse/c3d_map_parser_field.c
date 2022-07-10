/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:09:06 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 19:13:58 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static t_str	parse_ident(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != ' ' && b == '\t')
		i++;
	return ((t_str){self->reader.data + self->reader.con, i});
}

static void	consume_line(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n')
		i++;
	if (b == '\n')
		i++;
	ft_reader_consume(&self->reader, i);
}

static void	skip_spaces(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && (b == ' ' || b == '\t'))
		i++;
	ft_reader_consume(&self->reader, i);
}

static void	parse_pathname(t_map_parser *self, t_str ident, char **result)
{
	size_t	i;
	size_t	j;
	uint8_t	b;

	if (*result)
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str}' has already been defined",
			self->line, ident);
		consume_line(self);
		return ;
	}
	skip_spaces(self);
	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n')
		i++;
	if (b == '\n')
		i++;
	j = i;
	while (ft_reader_get(&self->reader, j - 1, &b)
		&& (b == '\n' || b == ' ' || b == '\t'))
		j--;
	*result = ft_str_ndup(self->reader.data + self->reader.con, j);
	ft_reader_consume(&self->reader, i);
}

static bool	str_to_uint8(t_str str, uint8_t *result)
{
	*result = 0;
	while (str.len)
	{
		if ('0' > *str.data || *str.data > '9')
			return (false);
		if (*result > (UINT8_MAX - (*str.data - '0')) / 10)
			return (false);
		*result = 10 * *result + (*str.data - '0');
		str.data++;
		str.len--;
	}
	return (true);
}

static bool	parse_uint8(t_map_parser *self, uint8_t *result)
{
	size_t	i;
	size_t	j;
	uint8_t	b;
	t_str	str;

	skip_spaces(self);
	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n' && b != ',')
		i++;
	if (b == '\n' || b == ',')
		i++;
	j = i;
	while (ft_reader_get(&self->reader, j - 1, &b) && (b == ' ' || b == '\t'))
		j--;
	str = (t_str){self->reader.data + self->reader.con, j};
	if (!str_to_uint8(str, result))
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str?}' is not a valid byte",
			self->line, str);
		consume_line(self);
		return (false);
	}
	ft_reader_consume(&self->reader, i);
	return (true);
}

static void	parse_color(t_map_parser *self, t_str ident, t_color *result)
{
	if (result->red != 0 || result->green != 0 || result->blue != 0)
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str}' has already been defined",
			self->line, ident);
		consume_line(self);
		return ;
	}
	if (!parse_uint8(self, &result->red)
		|| !parse_uint8(self, &result->green)
		|| !parse_uint8(self, &result->blue))
		consume_line(self);
}

bool	c3d_map_parser_field(t_map_parser *self)
{
	uint8_t	byte;
	t_str	id;

	if (!ft_reader_get(&self->reader, 0, &byte) || byte == ' ' || byte == '\t')
		return (false);
	id = parse_ident(self);
	if (id.len == 2 && id.data[0] == 'N' && id.data[1] == 'O')
		parse_pathname(self, id, &self->map->north_texture);
	else if (id.len == 2 && id.data[0] == 'E' && id.data[1] == 'A')
		parse_pathname(self, id, &self->map->east_texture);
	else if (id.len == 2 && id.data[0] == 'S' && id.data[1] == 'O')
		parse_pathname(self, id, &self->map->south_texture);
	else if (id.len == 2 && id.data[0] == 'W' && id.data[1] == 'E')
		parse_pathname(self, id, &self->map->west_texture);
	else if (id.len == 1 && id.data[0] == 'C')
		parse_color(self, id, &self->map->ceiling_color);
	else if (id.len == 1 && id.data[0] == 'F')
		parse_color(self, id, &self->map->floor_color);
	else
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str}' is not a known identifier",
			self->line, id);
		consume_line(self);
	}
}
