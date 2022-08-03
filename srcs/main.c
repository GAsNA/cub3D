/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:23:30 by nmathieu          #+#    #+#             */
/*   Updated: 2022/08/03 20:30:52 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "X11/X.h"
#include "c3d_map.h"
#include "c3d_game.h"

static void	start_game(const t_map *map)
{
	t_unwind	unwind_index;
	t_game		g;

	c3d_game_load(&g, map);
	unwind_index = ft_unwind(&g, c3d_game_unload);
	mlx_hook(g.win, DestroyNotify, 0, c3d_game_destroy_hook, &g);
	mlx_hook(g.win, KeyPress, KeyPressMask, c3d_game_key_pressed_hook, &g);
	mlx_hook(g.win, KeyRelease, KeyReleaseMask, c3d_game_key_released_hook, &g);
	mlx_loop_hook(g.mlx, c3d_game_loop_hook, &g);
	mlx_loop(g.mlx);
	ft_unwind_to(unwind_index);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac <= 0)
		return (1);
	if (ac != 2)
		return (ft_efmt("Usage: {s} <filename>\n", av[0]), 1);
	if (!c3d_map_parse(av[1], &map))
		return (1);
	ft_unwind(&map, c3d_map_free);
	start_game(&map);
	return (ft_unwind_to(0), 0);
}
