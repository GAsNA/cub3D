/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_key_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:01:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/14 15:32:19 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "X11/keysym.h"
#include "X11/X.h"
#include "mlx.h"

bool	*bind_keysym(KeySym keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w)
		return (&game->input.forward);
	if (keysym == XK_S || keysym == XK_s)
		return (&game->input.backward);
	if (keysym == XK_A || keysym == XK_a)
		return (&game->input.left);
	if (keysym == XK_D || keysym == XK_d)
		return (&game->input.right);
	if (keysym == XK_Up)
		return (&game->input.look_up);
	if (keysym == XK_Left)
		return (&game->input.look_left);
	if (keysym == XK_Right)
		return (&game->input.look_right);
	if (keysym == XK_Down)
		return (&game->input.look_down);
	return (NULL);
}

int	c3d_game_key_pressed_hook(KeySym keysym, t_game *game)
{
	bool	*binding;

	if (keysym == XK_Escape)
		return (mlx_loop_end(game->mlx));
	binding = bind_keysym(keysym, game);
	if (binding)
		*binding = true;
	return (0);
}

int	c3d_game_key_released_hook(KeySym keysym, t_game *game)
{
	bool	*binding;

	binding = bind_keysym(keysym, game);
	if (binding)
		*binding = false;
	return (0);
}
