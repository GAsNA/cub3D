/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_free_canvas.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:21:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 23:23:28 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"

void	c3d_game_free_canvas(t_game *game)
{
	mlx_destroy_image(game->mlx, game->canvas.raw);
}
