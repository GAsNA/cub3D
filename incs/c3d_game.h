/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:56:39 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:20:19 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GAME_H
# define C3D_GAME_H

# include "c3d_map.h"
# include "c3d_types.h"

# include <X11/X.h>
# include <stddef.h>
# include <stdint.h>

/// A loaded image.
typedef struct s_img
{
	void		*raw;
	t_rgba		*data;
	uint32_t	width;
	uint32_t	height;
}	t_img;

/// Reads an image from the provided file.
void		c3d_img_load_file(void *mlx_ptr, const char *filename, t_img *res);

/// Creates an image.
void		c3d_img_create(
				void *mlx_ptr,
				uint32_t width,
				uint32_t height,
				t_img *result);

/// Information about the player.
typedef struct s_player
{
	t_vec2	pos;
	float	angle;

	float	delta_angle;
	float	velocity;

	t_vec2	mouse_look;
	t_vec2	look;
}	t_player;

/// Stores information about the inputs performed by the user.
typedef struct s_input
{
	bool		forward;
	bool		left;
	bool		right;
	bool		backward;

	bool		look_up;
	bool		look_down;
	bool		look_left;
	bool		look_right;

	int			delta_x;
	int			delta_y;
}	t_input;

typedef struct s_confetti
{
	t_vec2	pos;
	t_vec2	vel;
	t_rgb	color;
}	t_confetti;

/// Stores the state of the game.
typedef struct s_game
{
	void		*mlx;
	void		*win;

	t_img		north_texture;
	t_img		south_texture;
	t_img		east_texture;
	t_img		west_texture;
	t_img		car_background_texture;
	t_img		car_wheel_texture;
	t_img		line_texture;
	t_img		mini_car_texture;

	t_rgb		floor_color;
	t_rgb		ceiling_color;

	t_img		canvas;

	bool		is_on_line;

	size_t		width;
	size_t		height;
	t_tile		*tiles;

	size_t		confetti_count;
	t_confetti	*confettis;

	uint64_t	frames;
	uint32_t	lap;

	int			last_pointer_x;
	int			last_pointer_y;

	t_input		input;
	t_player	player;

	uint64_t	rng_state[2];
}	t_game;

// Initializes a `t_game` instance from the provided map.
void		c3d_game_load(t_game *game, const t_map *map);

/// Frees the resources allocated for `t_game` instance.
void		c3d_game_unload(t_game *game);

uint64_t	c3d_game_rand(t_game *game);

// The following functions are used to free the content of a `t_game` instance.
// They don't have any documentation because each one simply frees one of the
// fields of said type.

void		c3d_game_destroy_mlx(t_game *game);
void		c3d_game_destroy_window(t_game *game);
void		c3d_game_free_north_texture(t_game *game);
void		c3d_game_free_south_texture(t_game *game);
void		c3d_game_free_east_texture(t_game *game);
void		c3d_game_free_west_texture(t_game *game);
void		c3d_game_free_canvas(t_game *game);
void		c3d_game_free_final_canvas(t_game *game);
void		c3d_game_free_car_background_texture(t_game *game);
void		c3d_game_free_car_wheel_texture(t_game *game);
void		c3d_game_free_line_texture(t_game *game);
void		c3d_game_free_mini_car_texture(t_game *game);

// Those are the hooks passed to the MiniLibX to be called when an input from
// the user is sent to the window.

int			c3d_game_destroy_hook(t_game *game);
int			c3d_game_loop_hook(t_game *game);
int			c3d_game_key_pressed_hook(KeySym keysym, t_game *game);
int			c3d_game_key_released_hook(KeySym keysym, t_game *game);
int			c3d_game_pointer_hook(int x, int y, t_game *game);

#endif
