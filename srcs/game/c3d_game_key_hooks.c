/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_key_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:01:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 23:14:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "X11/keysym.h"
#include "X11/X.h"
#include "mlx.h"

int	c3d_game_key_pressed_hook(KeySym keysym, t_game *game)
{
	if (keysym == XK_Escape)
		return (mlx_loop_end(game->mlx));
	return (0);
}

int	c3d_game_key_released_hook(KeySym keysym, t_game *game)
{
	(void)game;
	(void)keysym;
	return (0);
}
