/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 20:36:08 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_H
# define C3D_MAP_H

# include "libft.h"

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

// A cardinal direction.
typedef enum e_dir
{
	C3D_DIR_NORTH = 1,
	C3D_DIR_EAST = 2,
	C3D_DIR_WEST = 4,
	C3D_DIR_SOUTH = 8,
}	t_dir;

// An RGB color.
typedef struct s_color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_color;

// Information about the player, as defined in a cub3D map.
typedef struct s_player
{
	uint32_t	x;
	uint32_t	y;
	t_dir		dir;
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

	t_player	player;
}	t_map;

// Parses a cub3d map from the provided file descriptor.
bool	c3d_map_parse_fd(int fd, t_map *result);

// Parses a cub3D map from the provided filename.
bool	c3d_map_parse(const char *filename, t_map *result);

// Frees the ressources that were allocated for a `t_map` instance.
void	c3d_map_free(t_map *self);

#endif
