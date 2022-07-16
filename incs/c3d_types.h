/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:46:18 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/16 20:49:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_TYPES_H
# define C3D_TYPES_H

# include <stdint.h>

// A 2D position.
typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

// A 3D position.
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

// An RGB color.
typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

/// An RGBA color.
typedef struct s_rgba
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
}	t_rgba;

// A cardinal direction.
typedef enum e_dir
{
	C3D_DIR_NORTH = 1,
	C3D_DIR_EAST = 2,
	C3D_DIR_WEST = 4,
	C3D_DIR_SOUTH = 8,
}	t_dir;

#endif
