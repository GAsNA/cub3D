/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_move_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:32:29 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:18:21 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_types.h"
#include "c3d_physics.h"
#include "c3d_settings.h"
#include <math.h>

inline static float	lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

static void	update_look_vector(t_game *game)
{
	float	target_x;
	float	target_y;

	target_x = C3D_LOOK_MOUSE_H * (float)game->input.delta_x
		/ (float)C3D_WIDTH;
	target_y = C3D_LOOK_MOUSE_V * (float)game->input.delta_y
		/ (float)C3D_HEIGHT;
	target_y += (float)game->input.look_down - (float)game->input.look_up;
	target_x += (float)game->input.look_right - (float)game->input.look_left;
	game->player.look.x = lerp(game->player.look.x, target_x, C3D_LOOK_SPEED);
	game->player.look.y = lerp(game->player.look.y, target_y, C3D_LOOK_SPEED);
}

static void	update_angle(t_game *game)
{
	float	target_delta_angle;

	target_delta_angle = ((float)game->input.right - (float)game->input.left)
		* C3D_PLAYER_TURN;
	game->player.delta_angle = lerp(game->player.delta_angle,
			target_delta_angle, C3D_PLAYER_TURN_TIME);
	game->player.angle += game->player.delta_angle * game->player.velocity
		* C3D_DELTA_TIME;
}

static float	compute_force(t_game *game)
{
	float	force;

	force = 0.0f;
	if (game->input.forward && !game->input.backward)
		force += C3D_PLAYER_FORCE * C3D_DELTA_TIME;
	if (game->input.backward && !game->input.forward)
	{
		if (game->player.velocity > 0.1f)
			force -= game->player.velocity * C3D_PLAYER_BREAK * C3D_DELTA_TIME;
		else
			force -= C3D_PLAYER_BW_FORCE * C3D_DELTA_TIME;
	}
	force -= game->player.velocity * C3D_PLAYER_DRAG;
	return (force);
}

void	c3d_game_move_player(t_game *game)
{
	float		old_posx;
	float		old_posy;
	const float	force = compute_force(game);

	update_look_vector(game);
	update_angle(game);
	game->player.velocity += force * C3D_DELTA_TIME;
	old_posx = game->player.pos.x;
	old_posy = game->player.pos.y;
	game->player.pos.x += (game->player.velocity * cosf(game->player.angle)
			* C3D_DELTA_TIME);
	game->player.pos.y += (game->player.velocity * sinf(game->player.angle)
			* C3D_DELTA_TIME);
	if (c3d_player_touches(game, C3D_TILE_WALL)
		|| c3d_player_touches(game, C3D_TILE_LINE))
	{
		game->player.pos.x = old_posx;
		game->player.pos.y = old_posy;
		game->player.velocity = 0;
		return ;
	}
}
