/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_update_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:33:11 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 20:13:23 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "math.h"
#include "c3d_physics.h"

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
			ft_fmt("Lap {u32} finished in {u64}\n", game->lap, game->frames);
			game->lap++;
		}
	}
	if (c3d_player_touches(game, C3D_TILE_RLINE))
		c3d_set_line(game, false);
}
