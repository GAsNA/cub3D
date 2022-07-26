/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_free_wall_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:55:17 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 20:57:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"

void	c3d_game_free_north_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->north_texture.raw);
}

void	c3d_game_free_south_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->south_texture.raw);
}

void	c3d_game_free_east_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->east_texture.raw);
}

void	c3d_game_free_west_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->west_texture.raw);
}
