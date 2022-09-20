/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_pointer_hook.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:01:21 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 16:22:46 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"

int	c3d_game_pointer_hook(int x, int y, t_game* game)
{
	if (game->last_pointer_x != -1)
		game->input.delta_x = x - game->last_pointer_x;
	if (game->last_pointer_y != -1)
		game->input.delta_y = y - game->last_pointer_y;
	game->last_pointer_x = x;
	game->last_pointer_y = y;
	return (0);
}
