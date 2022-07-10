/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:02:21 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 23:08:55 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"
#include <stdlib.h>

void	c3d_map_parser_init(t_map_parser *self, int fd, t_map *result)
{
	ft_mem_set(self, 0x00, sizeof(t_map_parser));
	ft_reader_init(&self->reader, fd);
	self->map = result;
}

static void	my_free(char **ptr)
{
	free(*ptr);
}

static void	free_line(struct s_map_parser_line *line)
{
	if (line->len)
		free(line->line);
}

void	c3d_map_parser_deinit(t_map_parser *self)
{
	ft_reader_deinit(&self->reader);
	ft_vec_free(
		(t_vec *)&self->lines, free_line, sizeof(struct s_map_parser_line));
	ft_vec_free(
		(t_vec *)&self->errors, my_free, sizeof(char *));
	if (self->walls.cap)
		free(self->walls.data);
}
