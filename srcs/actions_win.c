/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:31:41 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 17:36:29 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	close_win(t_all *all)
{
	all_free(all);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
		close_win(all);
	if (keycode == W || keycode == UP)
		go_up(all);
	else if (keycode == S || keycode == DOWN)
		go_down(all);
	else if (keycode == A || keycode == LEFT)
		go_left(all);
	else if (keycode == D || keycode == RIGHT)
		go_right(all);
	return (1);
}
