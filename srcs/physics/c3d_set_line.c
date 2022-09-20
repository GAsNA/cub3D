/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_set_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:01:35 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 20:06:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"

void	c3d_set_line(t_game *game, bool line)
{
	size_t	i;

	i = 0;
	if (line)
	{
		while (i < game->width * game->height)
		{
			if (game->tiles[i] == C3D_TILE_LINE_OPEN)
				game->tiles[i] = C3D_TILE_LINE;
			i++;
		}
	}
	else
	{
		while (i < game->width * game->height)
		{
			if (game->tiles[i] == C3D_TILE_LINE)
				game->tiles[i] = C3D_TILE_LINE_OPEN;
			i++;
		}
	}
}
