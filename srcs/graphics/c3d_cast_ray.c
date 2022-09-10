/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_cast_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:59 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/10 19:42:15 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "c3d_raycast.h"
#include "c3d_settings.h"

static void	populate_hit(t_ray *ray, t_hit *hit, bool side)
{
	if (side)
	{
		hit->distance = ((float)ray->y - ray->origin.y + (float)((1 - ray->step_y) / 2)) / ray->dir.y;
		if (ray->dir.y < 0)
			hit->dir = C3D_DIR_NORTH;
		else
			hit->dir = C3D_DIR_SOUTH;
		hit->tex_x = ray->origin.y + hit->distance * ray->dir.y;
		hit->tex_x -= floorf(hit->tex_x);
	}
	else
	{
		hit->distance = ((float)ray->x - ray->origin.x + (float)((1 - ray->step_x) / 2.0f)) / ray->dir.x;
		if (ray->dir.x < 0)
			hit->dir = C3D_DIR_WEST;
		else
			hit->dir = C3D_DIR_EAST;
		hit->tex_x = ray->origin.x + hit->distance * ray->dir.x;
		hit->tex_x -= floorf(hit->tex_x);
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
