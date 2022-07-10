/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 17:28:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_PARSER_H
# define C3D_MAP_PARSER_H

# include "libft.h"
# include "c3d_map.h"

// Stores the state required to parse a `t_map` instance.
typedef struct s_map_parser
{
	t_reader		reader;
	size_t			line;

	t_map			*map;
	struct s_map_parser_errors
	{
		char	**errors;
		size_t	len;
		size_t	cap;
	}	errors;
}	t_map_parser;

// Initializes a `t_map_parser` instance.
void	c3d_map_parser_init(t_map_parser *self, int fd, t_map *result);

// Frees the resources that were allocated for a `t_map_parser` instance.
void	c3d_map_parser_deinit(t_map_parser *self);

#endif
