/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:22:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:54:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map.h"
#include "libft.h"
#include <fcntl.h>

bool	c3d_map_parse(const char *filename, t_map *result, t_vec *errs)
{
	t_unwind	unwind_index;
	int			fd;
	bool		ret;

	fd = ft_open(filename, O_RDONLY);
	unwind_index = ft_unwind(&fd, ft_close);
	ret = c3d_map_parse_fd(fd, result, errs);
	return (ft_unwind_to(unwind_index), ret);
}
