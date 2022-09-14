/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:22:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/08 18:30:40 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_game.h"
#include "mlx.h"
#include <stdlib.h>

static void	load_images(t_game *game, const t_map *map)
{
	c3d_img_load_file(game->mlx, map->north_texture, &game->north_texture);
	ft_unwind(game, c3d_game_free_north_texture);
	c3d_img_load_file(game->mlx, map->south_texture, &game->south_texture);
	ft_unwind(game, c3d_game_free_south_texture);
	c3d_img_load_file(game->mlx, map->west_texture, &game->west_texture);
	ft_unwind(game, c3d_game_free_west_texture);
	c3d_img_load_file(game->mlx, map->east_texture, &game->east_texture);
	ft_unwind(game, c3d_game_free_east_texture);
	c3d_img_create(game->mlx, C3D_WIDTH, C3D_HEIGHT, &game->canvas);
	ft_unwind(game, c3d_game_free_canvas);
}

inline static float	dir_to_angle(t_dir dir)
{
	if (dir == C3D_DIR_EAST)
		return (0.0f);
	if (dir == C3D_DIR_NORTH)
		return (3.0f * PI / 2.0f);
	if (dir == C3D_DIR_WEST)
		return (PI);
	if (dir == C3D_DIR_SOUTH)
		return (PI / 2.0f);
	return (0.0f);
}

void	c3d_game_load(t_game *game, const t_map *map)
{
	t_unwind	unwind_index;

	ft_mem_set(game, 0x00, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_unwind_panic("failed to initialize MiniLibX");
	unwind_index = ft_unwind(game, c3d_game_destroy_mlx);
	game->win = mlx_new_window(game->mlx, C3D_WIDTH, C3D_HEIGHT, "Cub3D");
	if (!game->mlx)
		ft_unwind_panic("failed to create a window");
	ft_unwind(game, c3d_game_destroy_window);
	load_images(game, map);
	game->ceiling_color = map->ceiling_color;
	game->floor_color = map->floor_color;
	game->player.pos.x = (float)map->player.x;
	game->player.pos.y = (float)map->player.y;
	game->player.angle = dir_to_angle(map->player.dir);
	game->width = map->width;
	game->height = map->height;
	game->tiles = map->tiles;
	ft_unwind_defuse_to(unwind_index);
}

void	c3d_game_unload(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->north_texture.raw);
	mlx_destroy_image(game->mlx, game->south_texture.raw);
	mlx_destroy_image(game->mlx, game->east_texture.raw);
	mlx_destroy_image(game->mlx, game->west_texture.raw);
	mlx_destroy_image(game->mlx, game->canvas.raw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
