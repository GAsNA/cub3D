/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:25:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 19:14:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"
#include "libft.h"

static void	print_errors(char **errors, size_t len)
{
	ft_fmt("Error\n");
	while (len)
	{
		ft_fmt(" - {s}\n", *errors);
		len--;
		errors++;
	}
}

static void	do_parse(t_map_parser *self)
{
	while ((c3d_map_parser_skip_empty_lines(self), c3d_map_parser_field(self)))
		;
	c3d_map_parser_skip_empty_lines(self);
	c3d_map_parser_map(self);
}

bool	c3d_map_parse_fd(int fd, t_map *result)
{
	t_unwind		unwind_index;
	t_map_parser	parser;

	ft_mem_set(result, 0x00, sizeof(t_map));
	unwind_index = ft_unwind(result, c3d_map_free);
	ft_parser_init(&parser, fd, result);
	ft_unwind(&parser, c3d_map_parser_deinit);
	do_parse(&parser);
	if (parser.errors.len != 0)
	{
		print_errors(parser.errors.errors, parser.errors.len);
		return (ft_unwind_to(unwind_index), false);
	}
	ft_unwind_defuse(unwind_index);
	return (ft_unwind_to(unwind_index), false);
}
