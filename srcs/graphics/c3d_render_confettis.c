/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_confettis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:01:02 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:07:37 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_graphics.h"
#include "c3d_game.h"

inline static void	put_pixel(t_game *game, uint32_t x, uint32_t y, t_rgb color)
{
	if (x >= game->canvas.width || y >= game->canvas.height)
		return ;
	game->canvas.data[y * game->canvas.width + x].rgb = color;
}

static void	put_confetti(t_game *game, uint32_t x, uint32_t y, t_rgb color)
{
	uint32_t	i;
	uint32_t	j;

	j = 0;
	while (j < 6)
	{
		i = 0;
		while (i < 6)
		{
			put_pixel(game, x + i - 3, y + j - 3, color);
			i++;
		}
		j++;
	}
}

void	c3d_render_confetti(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->confetti_count)
	{
		put_confetti(game, (uint32_t)game->confettis[i].pos.x,
			(uint32_t)game->confettis[i].pos.y, game->confettis[i].color);
		i++;
	}
}
