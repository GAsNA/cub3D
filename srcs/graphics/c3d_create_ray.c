/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_create_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:14:32 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/08 18:58:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "c3d_raycast.h"
#include "c3d_settings.h"

void	c3d_create_ray(t_ray *ray, t_vec2 pos, float angle, uint32_t x)
{
	const float		cam_x = 2.0f * (x / (float)C3D_WIDTH) - 1.0f;
	const t_vec2	vecdir = (t_vec2){cosf(angle), sinf(angle)};
	const t_vec2	planepos
		= (t_vec2){vecdir.y * C3D_FOV, -vecdir.x * C3D_FOV};

	// ray_calculs
	ray->dir.x = vecdir.x + planepos.x * cam_x;
	ray->dir.y = vecdir.y + planepos.y * cam_x;
	ray->delta.x = sqrtf(1.0f + (ray->dir.y * ray->dir.y)
		/ (ray->dir.x * ray->dir.x));
	ray->delta.y = sqrtf(1.0f + (ray->dir.x * ray->dir.x)
		/ (ray->dir.y * ray->dir.y));
	ray->origin = pos;
	ray->x = (uint32_t)pos.x;
	ray->y = (uint32_t)pos.y;

	// get_stop_for_ray
	if (ray->dir.x < 0.0f)
	{
		ray->step_x = -1;
		ray->side.x = (pos.x - (float)ray->x) * ray->delta.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side.x = ((float)ray->x + 1.0f - pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0.0f)
	{
		ray->step_y = -1;
		ray->side.y = (pos.y - (float)ray->y) * ray->delta.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side.y = ((float)ray->y + 1.0f - pos.y) * ray->delta.y;
	}
}
