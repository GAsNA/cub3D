/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:06:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/16 23:08:13 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include <stdbool.h>
#include <math.h>

bool	c3d_raycast(t_vec2 origin, float angle, t_hit *result)
{
	origin.x += cosf(angle) * angle / 3.0f;
	origin.y += sinf(angle) * angle / 3.0f;
	result->dir = C3D_DIR_EAST;
	result->pos = origin;
	return (true);
}
