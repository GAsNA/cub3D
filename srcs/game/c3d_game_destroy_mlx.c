/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_destroy_mlx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:32:02 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 22:40:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"
#include <stdlib.h>

void	c3d_game_destroy_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	c3d_game_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
}
