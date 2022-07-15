/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:56:39 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 20:54:50 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GAME_H
# define C3D_GAME_H

# include "c3d_map.h"
# include "c3d_math.h"

# include <stddef.h>
# include <stdint.h>

/// A loaded image.
typedef struct s_img
{
	void		*raw;
	size_t		line_size;
	t_rgba		*data;
	uint32_t	width;
	uint32_t	height;
}	t_img;

/// Reads an image from the provided file.
void	c3d_img_load_file(void *mlx_ptr, const char *filename, t_img *result);

/// Creates an image.
void	c3d_img_create(
			void *mlx_ptr,
			uint32_t width,
			uint32_t height,
			t_img *result);

/// Stores the state of the game.
typedef struct s_game
{
	void	*mlx;

	t_img	north_texture;
	t_img	south_texture;
	t_img	east_texture;
	t_img	west_texture;

	t_rgb	floor_color;
	t_rgb	ceiling_color;
}	t_game;

// Initializes a `t_game` instance from the provided map.
void	c3d_game_load(t_game *game, const t_map *map);

/// Frees the resources allocated for `t_game` instance.
void	c3d_game_unload(t_game *game);

// The following functions are used to free the content of a `t_game` instance.
// They don't have any documentation because each one simply frees one of the
// fields of said type.

void	c3d_game_free_north_texture(t_game *game);
void	c3d_game_free_south_texture(t_game *game);
void	c3d_game_free_east_texture(t_game *game);
void	c3d_game_free_west_texture(t_game *game);

#endif
