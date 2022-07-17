/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:06:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/17 08:54:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include <stdbool.h>
#include <math.h>

bool	c3d_raycast(t_vec2 origin, float angle, t_hit *result)
{
	result->dir = C3D_DIR_EAST;
	result->distance = 0.2f * (angle + 50.0f);
	printf("%f\n", result->distance);
	(void)origin;
	return (true);
}
