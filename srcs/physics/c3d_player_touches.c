/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_touches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:48:48 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 19:53:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_game.h"

static bool	pos_touches(t_game *game, float posx, float posy, t_tile tile)
{
	return ((size_t)posx >= game->width
		|| (size_t)posy >= game->height
		|| game->tiles[(size_t)posy * game->width + (size_t)posx] == tile);
}

bool	c3d_player_touches(t_game *game, t_tile tile)
{
	const float	posx = game->player.pos.x;
	const float	posy = game->player.pos.y;

	return (pos_touches(game, posx + C3D_COLLIDER, posy + C3D_COLLIDER, tile)
		|| pos_touches(game, posx - C3D_COLLIDER, posy + C3D_COLLIDER, tile)
		|| pos_touches(game, posx - C3D_COLLIDER, posy - C3D_COLLIDER, tile)
		|| pos_touches(game, posx + C3D_COLLIDER, posy - C3D_COLLIDER, tile));
}
