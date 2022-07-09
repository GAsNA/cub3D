/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/09 18:03:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_H
# define C3D_MAP_H

# include <stddef.h>
# include <stdint.h>

// A cardinal direction.
typedef enum e_card
{
	C3D_DIR_NORTH = 1U << 0U,
	C3D_DIR_EAST = 1U << 1U,
	C3D_DIR_WEST = 1U << 2U,
	C3D_DIR_EAST = 1U << 3U,
}	t_card;

// An RGB color.
typedef struct s_color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_color;

// An axis-aligned wall defined by its bounds.
//
// The `min_x` and `max_y` bounds are included in the wall, the `max_x` and
// `max_y` bounds are *not* included.
typedef struct s_wall
{
	uint32_t	min_x;
	uint32_t	min_y;
	uint32_t	max_x;
	uint32_t	max_y;
}	t_wall;

// Information about the player, as defined in a cub3D map.
typedef struct s_player
{
	uint32_t	x;
	uint32_t	y;
	t_card		dir;
}	t_player;

// Stores a fully parsed map.
typedef struct s_map
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	t_color		floor_color;
	t_color		ceiling_color;

	size_t		width;
	size_t		height;

	t_wall		*walls;
	size_t		wall_count;

	t_player	player;
}	t_map;

// Parses a cub3d map from the provided file descriptor.
void	c3d_map_parse_fd(int fd);

// Parses a cub3D map from the provided filename.
void	c3d_map_parse(const char *filename);

// Frees the ressources that were allocated for a `t_map` instance.
void	c3d_map_free(t_map *self);

#endif
