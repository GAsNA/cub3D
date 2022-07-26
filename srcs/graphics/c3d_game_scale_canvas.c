/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_scale_canvas.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:29:20 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 23:37:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"

#define P C3D_PIXEL_SIZE

void	c3d_game_scale_canvas(t_game *game)
{
	uint32_t		x;
	uint32_t		y;

	y = 0;
	while (y < game->final_canvas.height)
	{
		x = 0;
		while (x < game->final_canvas.width)
		{
			game->final_canvas.data[y * game->final_canvas.width + x]
				= game->canvas.data[(y / P) * game->canvas.width + (x / P)];
			x++;
		}
		y++;
	}
}
