/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:25:14 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:54:26 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map.h"
#include "libft.h"

bool	c3d_map_parse_fd(int fd, t_map *result, t_vec *errs)
{
	t_unwind	unwind_index;
	t_reader	reader;

	ft_mem_set(result, 0x00, sizeof(t_map));
	ft_mem_set(errs, 0x00, sizeof(t_vec));
	ft_reader_init(&reader, fd);
	unwind_index = ft_unwind(&reader, ft_reader_deinit);
	return (ft_unwind_to(unwind_index), false);
}
