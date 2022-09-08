/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:14:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/08 18:56:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_RAYCAST_H
# define C3D_RAYCAST_H

# include "c3d_types.h"
# include "c3d_game.h"
// Describes a ray that have been launched.
typedef struct s_ray
{
	t_vec2	dir;
	t_vec2	delta;
	t_vec2	side;
	t_vec2	origin;

	uint32_t	x;
	uint32_t	y;
	int32_t		step_x;
	int32_t		step_y;
}	t_ray;

// Describes a hit.
typedef struct s_hit
{
	float	distance;
	t_dir	dir;
}	t_hit;

void	c3d_create_ray(t_ray *ray, t_vec2 pos, float angle, uint32_t x);
bool	c3d_cast_ray(t_ray *ray, t_game *game, t_hit *hit);

#endif
