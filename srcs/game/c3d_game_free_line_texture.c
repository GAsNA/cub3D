/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_free_line_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:57:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 18:38:01 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d_game.h"

void	c3d_game_free_line_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->line_texture.raw);
}
