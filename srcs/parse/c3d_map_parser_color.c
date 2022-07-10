/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:18:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:22:33 by nmathieu         ###   ########.fr       */
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

static bool	parse_uint8(t_map_parser *self, uint8_t *result)
{
	size_t	i;
	size_t	j;
	uint8_t	b;
	t_str	str;

	c3d_map_parser_skip_spaces(self);
	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n' && b != ',')
		i++;
	if (b == '\n' || b == ',')
		i++;
	j = i;
	while (ft_reader_get(&self->reader, j - 1, &b) && (b == ' ' || b == '\t'))
		j--;
	str = (t_str){(void *)self->reader.data + self->reader.con, j};
	if (!str_to_uint8(str, result))
	{
		c3d_map_parser_push_error(
			self, "line {ulong}: '{str?}' is not a valid byte",
			self->line, str);
		c3d_map_parser_skip_line(self);
		return (false);
	}
	ft_reader_consume(&self->reader, i);
	return (true);
}

bool	c3d_map_parser_color(
			t_map_parser *self,
			t_str ident,
			t_color *result,
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
	if (!parse_uint8(self, &result->red)
		|| !parse_uint8(self, &result->green)
		|| !parse_uint8(self, &result->blue))
		return (c3d_map_parser_skip_line(self), false);
	return (true);
}
