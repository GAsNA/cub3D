/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:44:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/11 18:22:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

bool	c3d_map_parser_skip_empty_lines(t_map_parser *self)
{
	uint8_t	byte;
	size_t	index;

	index = 0;
	while (ft_reader_get(&self->reader, index, &byte))
	{
		if (byte != ' ' && byte != '\t' && byte != '\n')
			return (false);
		index++;
		if (byte == '\n')
		{
			self->line++;
			ft_reader_consume(&self->reader, index);
			index = 0;
		}
	}
	ft_reader_consume(&self->reader, index);
	return (true);
}

void	c3d_map_parser_skip_spaces(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && (b == ' ' || b == '\t'))
		i++;
	ft_reader_consume(&self->reader, i);
}

void	c3d_map_parser_skip_line(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b) && b != '\n')
		i++;
	if (b == '\n')
	{
		i++;
		self->line++;
	}
	ft_reader_consume(&self->reader, i);
}

bool	c3d_map_parser_is_end_of_file(t_map_parser *self)
{
	size_t	i;
	uint8_t	b;

	i = 0;
	while (ft_reader_get(&self->reader, i, &b))
	{
		if (b != '\n' && b != ' ' && b != '\t')
			return (false);
		i++;
	}
	return (true);
}
