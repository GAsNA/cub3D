/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 20:05:05 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_H
# define C3D_MAP_H

# include "libft.h"
# include "c3d_types.h"

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# define C3D_TILE_VOID 0U
# define C3D_TILE_WALL 1U
# define C3D_TILE_FLOOR 2U
# define C3D_TILE_TRACK 3U
# define C3D_TILE_LINE 4U
# define C3D_TILE_LINE_OPEN 5U
# define C3D_TILE_RLINE 6U
# define C3D_TILE_RLINE_OUTSIDE 7U

/// A tile.
typedef uint8_t	t_tile;

// Stores a fully parsed map.
typedef struct s_map
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	t_rgb		floor_color;
	t_rgb		ceiling_color;

	size_t		width;
	size_t		height;
	t_tile		*tiles;

	struct s_map_player
	{
		uint32_t	x;
		uint32_t	y;
		t_dir		dir;
	}	player;
}	t_map;

// Parses a cub3d map from the provided file descriptor.
bool	c3d_map_parse_fd(int fd, t_map *result);

// Parses a cub3D map from the provided filename.
bool	c3d_map_parse(const char *filename, t_map *result);

// Frees the ressources that were allocated for a `t_map` instance.
void	c3d_map_free(t_map *self);

#endif
