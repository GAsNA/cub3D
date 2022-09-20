/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_loop_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:41:13 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 20:10:21 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_graphics.h"
#include "c3d_physics.h"

int	c3d_game_loop_hook(t_game *game)
{
	c3d_game_simulate(game);
	game->input.delta_x = 0;
	game->input.delta_y = 0;
	c3d_game_render(game);
	game->frames++;
	return (0);
}
