/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:25:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/12 10:37:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"
#include "libft.h"

#define MAX_ERRORS 16

static void	print_errors(char **errors, size_t len)
{
	ft_efmt("Error\n");
	while (len)
	{
		ft_efmt(" - {s}\n", *errors);
		len--;
		errors++;
	}
}

static void	do_parse(t_map_parser *self)
{
	while (self->errors.len < MAX_ERRORS
		&& (c3d_map_parser_skip_empty_lines(self), c3d_map_parser_field(self)))
		;
	c3d_map_parser_validate_fields(self);
	if (self->errors.len >= MAX_ERRORS)
	{
		c3d_map_parser_push_error(self, "too many errors; fix your map!");
		return ;
	}
	c3d_map_parser_skip_empty_lines(self);
	if (!c3d_map_parser_map(self))
		return ;
	if (!c3d_map_parser_is_enclosed(self))
		return ;
}

bool	c3d_map_parse_fd(int fd, t_map *result)
{
	t_unwind		unwind_index;
	t_map_parser	parser;

	ft_mem_set(result, 0x00, sizeof(t_map));
	unwind_index = ft_unwind(result, c3d_map_free);
	c3d_map_parser_init(&parser, fd, result);
	ft_unwind(&parser, c3d_map_parser_deinit);
	do_parse(&parser);
	if (parser.errors.len != 0)
		return (
			print_errors(parser.errors.data, parser.errors.len),
			ft_unwind_to(unwind_index), false);
	return (ft_unwind_defuse(unwind_index), ft_unwind_to(unwind_index), true);
}
