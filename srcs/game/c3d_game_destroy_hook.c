/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_destroy_hook.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:46:26 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 22:51:34 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"

int		c3d_game_destroy_hook(t_game *game)
{
	return (mlx_loop_end(game->mlx));
}
