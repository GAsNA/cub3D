/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_validate_fields.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:17:54 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 21:33:04 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

bool	c3d_map_parser_validate_fields(t_map_parser *self)
{
	const size_t	start_len = self->errors.len;

	if (!self->has_ceiling_color)
		c3d_map_parser_push_error(self, "no ceiling color (id C)");
	if (!self->has_floor_color)
		c3d_map_parser_push_error(self, "no floor color (id F)");
	if (!self->map->north_texture)
		c3d_map_parser_push_error(self, "no north texture (id NO)");
	if (!self->map->east_texture)
		c3d_map_parser_push_error(self, "no east texture (id EA)");
	if (!self->map->south_texture)
		c3d_map_parser_push_error(self, "no south texture (id SO)");
	if (!self->map->west_texture)
		c3d_map_parser_push_error(self, "no west texture (id WE)");
	return (start_len == self->errors.len);
}
