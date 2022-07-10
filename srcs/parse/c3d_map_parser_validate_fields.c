/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_validate_fields.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:17:54 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:28:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

bool	c3d_map_parser_validate_fields(t_map_parser *self)
{
	const size_t	start_len = self->errors.len;

	if (!self->has_ceiling_color)
		c3d_map_parser_push_error(self, "no ceiling color defined (id C)");
	if (!self->has_floor_color)
		c3d_map_parser_push_error(self, "no floor color defined (id F)");
	if (!self->map->north_texture)
		c3d_map_parser_push_error(self, "no north texture defined (id NO)");
	if (!self->map->east_texture)
		c3d_map_parser_push_error(self, "no east texture defined (id EA)");
	if (!self->map->south_texture)
		c3d_map_parser_push_error(self, "no south texture defined (id SO)");
	if (!self->map->west_texture)
		c3d_map_parser_push_error(self, "no west texture defined (id WE)");
	return (start_len == self->errors.len);
}
