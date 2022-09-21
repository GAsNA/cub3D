/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_update_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:33:11 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 11:28:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"
#include "math.h"
#include "c3d_physics.h"

static void	spawn_confettis(t_game *game)
{
	size_t	i;

	i = 0;
	game->confetti_count = C3D_CONFETTI_MAX;
	while (i < C3D_CONFETTI_MAX)
	{
		game->confettis[i].pos = (t_vec2){(float)(c3d_game_rand(game) % (C3D_WIDTH + 20)) - 10.0f, (float)(C3D_HEIGHT - 10 + c3d_game_rand(game) % 40)};
		game->confettis[i].vel = (t_vec2){(float)(c3d_game_rand(game) % 60) - 30.0f, -(float)(c3d_game_rand(game) % 100) - 50.0f};
		game->confettis[i].color.red = c3d_game_rand(game) % 256;
		game->confettis[i].color.green = c3d_game_rand(game) % 256;
		game->confettis[i].color.blue = c3d_game_rand(game) % 256;
		i++;
	}
}

void	c3d_game_update_line(t_game *game)
{
	if (c3d_player_touches(game, C3D_TILE_LINE_OPEN))
	{
		game->is_on_line = true;
	}
	else if (game->is_on_line)
	{
		game->is_on_line = false;
		c3d_set_line(game, true);
		if (game->lap == 0)
		{
			game->lap = 1;
			game->frames = 0;
		}
		else
		{
			spawn_confettis(game);
			ft_fmt("Lap {u32} finished in {u64}\n", game->lap, game->frames);
			game->lap++;
		}
	}
	if (c3d_player_touches(game, C3D_TILE_RLINE))
		c3d_set_line(game, false);
}
