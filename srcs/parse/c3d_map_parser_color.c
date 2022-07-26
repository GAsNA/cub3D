/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:18:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 20:48:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

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

static bool	parse_uint8(t_map_parser *self, uint8_t *result, char sep)
{
	size_t	i;
	size_t	j;
	uint8_t	b;
	t_str	str;

	c3d_map_parser_skip_spaces(self);
	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n' && b != sep)
		i++;
	j = i;
	if (b == sep)
		i++;
	if (b == '\n')
		self->line++;
	while (ft_reader_get(&self->reader, j - 1, &b) && (b == ' ' || b == '\t'))
		j--;
	str = (t_str){(void *)self->reader.data + self->reader.con, j};
	if (!str_to_uint8(str, result))
		return (
			c3d_map_parser_push_error(
				self, "line {ulong}: '{str?}' is not a valid byte",
				self->line, str), ft_reader_consume(&self->reader, i), false);
	ft_reader_consume(&self->reader, i);
	return (true);
}

bool	c3d_map_parser_color(
			t_map_parser *self,
			t_str ident,
			t_rgb *result,
			bool *done)
{
	if (*done)
		return (
			c3d_map_parser_push_error(
				self, "line {ulong}: '{str}' has already been defined",
				self->line, ident),
			c3d_map_parser_skip_line(self),
			false);
	*done = true;
	if (!parse_uint8(self, &result->red, ',')
		|| !parse_uint8(self, &result->green, ',')
		|| !parse_uint8(self, &result->blue, '\n'))
		return (c3d_map_parser_skip_line(self), false);
	return (true);
}
