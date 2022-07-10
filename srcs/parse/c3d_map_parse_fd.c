/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:25:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:27:10 by nmathieu         ###   ########.fr       */
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
	if (!c3d_map_parser_validate_fields(self))
		return ;
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
	return (ft_unwind_defuse(unwind_index), ft_unwind_to(unwind_index), false);
}
