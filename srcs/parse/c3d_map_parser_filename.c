/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_filename.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:15:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/11 11:40:50 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static char	*trim_str_right(t_map_parser *self, size_t end)
{
	size_t	j;
	uint8_t	b;

	j = end;
	while (ft_reader_get(&self->reader, j - 1, &b)
		&& (b == '\n' || b == ' ' || b == '\t'))
		j--;
	return (ft_str_ndup((void *)self->reader.data + self->reader.con, j));
}

bool	c3d_map_parser_filename(t_map_parser *self, t_str ident, char **result)
{
	size_t	i;
	uint8_t	b;

	if (*result)
		return (
			c3d_map_parser_push_error(
				self, "line {ulong}: '{str}' has already been defined",
				self->line, ident),
			c3d_map_parser_skip_line(self),
			false);
	c3d_map_parser_skip_spaces(self);
	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n')
		i++;
	if (b == '\n')
	{
		i++;
		self->line++;
	}
	*result = trim_str_right(self, i);
	ft_reader_consume(&self->reader, i);
	return (true);
}
