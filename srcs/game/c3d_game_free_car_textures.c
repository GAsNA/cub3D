/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_free_car_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:20:04 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 10:02:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d_game.h"

void	c3d_game_free_car_background_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->car_background_texture.raw);
}

void	c3d_game_free_car_wheel_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->car_wheel_texture.raw);
}

void	c3d_game_free_mini_car_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mini_car_texture.raw);
}
