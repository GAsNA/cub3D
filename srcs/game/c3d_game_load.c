/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:22:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 21:17:54 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"
#include <stdlib.h>

void	c3d_game_load(t_game *game, const t_map *map)
{
	t_unwind	unwind_index;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_unwind_panic("failed to initialize the MiniLibX");
	c3d_img_load_file(game->mlx, map->north_texture, &game->north_texture);
	unwind_index = ft_unwind(&game, c3d_game_free_north_texture);
	c3d_img_load_file(game->mlx, map->south_texture, &game->south_texture);
	ft_unwind(&game, c3d_game_free_south_texture);
	c3d_img_load_file(game->mlx, map->west_texture, &game->west_texture);
	ft_unwind(&game, c3d_game_free_west_texture);
	c3d_img_load_file(game->mlx, map->east_texture, &game->east_texture);
	ft_unwind(&game, c3d_game_free_east_texture);
	game->ceiling_color = map->ceiling_color;
	game->floor_color = map->floor_color;
	ft_unwind_defuse_to(unwind_index);
}

void	c3d_game_unload(t_game *game)
{
	mlx_destroy_image(game->mlx, game->north_texture.raw);
	mlx_destroy_image(game->mlx, game->south_texture.raw);
	mlx_destroy_image(game->mlx, game->east_texture.raw);
	mlx_destroy_image(game->mlx, game->west_texture.raw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
