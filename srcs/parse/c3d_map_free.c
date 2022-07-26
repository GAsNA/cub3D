/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:20:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 12:50:20 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "c3d_map.h"
#include <stdlib.h>

void	c3d_map_free(t_map *self)
{
	free(self->north_texture);
	free(self->south_texture);
	free(self->west_texture);
	free(self->east_texture);
	free(self->tiles);
}
