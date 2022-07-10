/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:22:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:22:49 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map.h"
#include "libft.h"
#include <fcntl.h>

bool	c3d_map_parse(const char *file, t_map *result)
{
	t_unwind	unwind_index;
	int			fd;
	bool		ret;
	const char	*ext;

	ext = ft_str_rfind(file, '.');
	if (!ext || ext == file || ft_str_cmp(ext, ".cub") != 0)
		ft_unwind_panic("'{s?}' is not a '.cub' file", file);
	fd = ft_open(file, O_RDONLY);
	unwind_index = ft_unwind(&fd, ft_close);
	ret = c3d_map_parse_fd(fd, result);
	return (ft_unwind_to(unwind_index), ret);
}
