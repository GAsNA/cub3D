/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:23:30 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 22:19:41 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "c3d_map.h"

static void	print_map(t_map *self)
{
	ft_fmt("NO: {s?}\n", self->north_texture);
	ft_fmt("SO: {s?}\n", self->south_texture);
	ft_fmt("WE: {s?}\n", self->west_texture);
	ft_fmt("EA: {s?}\n\n", self->east_texture);
	ft_fmt("C: {u8},{u8},{u8}\n",
		self->ceiling_color.red,
		self->ceiling_color.green,
		self->ceiling_color.blue);
	ft_fmt("F: {u8},{u8},{u8}\n\n",
		self->floor_color.red,
		self->floor_color.green,
		self->floor_color.blue);
	ft_fmt("Player Dir: {uint}\n", self->player.dir);
	ft_fmt("Player Pos: {u32}, {u32}\n", self->player.x, self->player.y);
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
	print_map(&map);
	return (ft_unwind_to(0), 0);
}
