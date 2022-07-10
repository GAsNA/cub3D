/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:25:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 17:27:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"
#include "libft.h"

bool	c3d_map_parse_fd(int fd, t_map *result)
{
	t_unwind		unwind_index;
	t_map_parser	parser;

	ft_mem_set(result, 0x00, sizeof(t_map));
	unwind_index = ft_unwind(result, c3d_map_free);
	ft_parser_init(&parser, fd, result);
	ft_unwind(&parser, c3d_map_parser_deinit);

	return (ft_unwind_to(unwind_index), false);
}
