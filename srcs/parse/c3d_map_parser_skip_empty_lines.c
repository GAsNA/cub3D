/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_skip_empty_lines.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:44:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 18:08:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

void	c3d_map_parser_skip_empty_lines(t_map_parser *self)
{
	uint8_t	byte;
	size_t	index;

	if (!ft_reader_refill(&self->reader, 64))
		return ;
	index = 0;
	while (ft_reader_get(&self->reader, index, &byte))
	{
		if (byte != ' ' && byte != '\t')
			return ;
		index++;
		if (byte == '\n')
		{
			ft_reader_consume(&self->reader, index);
			index = 0;
		}
	}
}
