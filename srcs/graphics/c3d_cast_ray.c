/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_cast_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:59 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/08 19:02:27 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "c3d_raycast.h"
#include "c3d_settings.h"

static void	populate_hit(t_ray *ray, t_hit *hit, bool side)
{
	if (side)
	{
		hit->distance = ((float)ray->y - ray->origin.y
			+ (1.0f - (float)ray->step_y) / 2.0f) / ray->dir.y;
		hit->dir = C3D_DIR_SOUTH;
	}
	else
	{
		hit->distance = ((float)ray->x - ray->origin.x
			+ (1.0f - (float)ray->step_x) / 2.0f) / ray->dir.x;
		hit->dir = C3D_DIR_WEST;
	}
}

bool	c3d_cast_ray(t_ray *ray, t_game *game, t_hit *hit)
{
	bool	side;

	while (true)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->x += ray->step_x;
			side = false;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->y += ray->step_y;
			side = true;
		}
		if (ray->x >= C3D_WIDTH || ray->y >= C3D_HEIGHT)
			return (false);
		if (game->tiles[ray->y * game->width + ray->x] == C3D_TILE_WALL)
			return (populate_hit(ray, hit, side), true);
	}
}
