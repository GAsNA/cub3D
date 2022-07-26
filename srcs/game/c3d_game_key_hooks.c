/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_key_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:01:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 15:27:30 by nmathieu         ###   ########.fr       */
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
	else if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		game->input.forward = true;
	else if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		game->input.backward = true;
	else if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		game->input.left = true;
	else if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		game->input.right = true;
	return (0);
}

int	c3d_game_key_released_hook(KeySym keysym, t_game *game)
{
	if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		game->input.forward = false;
	else if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		game->input.backward = false;
	else if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		game->input.left = false;
	else if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		game->input.right = false;
	return (0);
}
