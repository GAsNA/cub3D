/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:46:18 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 04:49:04 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MATH_H
# define C3D_MATH_H

// A 2D position.
typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

// A 3D position.
typedef struct s_vec3
{
	float x;
	float y;
	float z;
}	t_vec3;

#endif
