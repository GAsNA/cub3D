/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:23:30 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/13 15:53:46 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_strdup_noM(char des[36], char src[36])
{
	int	i;

	i = -1;
	while (++i < 36)
		des[i] = src[i];
}

int	main(void)
{
	t_game	game;

	ft_strdup_noM(game.map[0], "111111111111111111111111111111111111");
	ft_strdup_noM(game.map[1], "100000000000000000000000000000000001");
	ft_strdup_noM(game.map[2], "120010000000200000000000000000000001");
	ft_strdup_noM(game.map[3], "100010001000000030000000000000000001");
	ft_strdup_noM(game.map[4], "100000000000000000000000000000000001");
	ft_strdup_noM(game.map[5], "120202020200200000000000000000000001");
	ft_strdup_noM(game.map[6], "100000000000000000000000000000000001");
	ft_strdup_noM(game.map[7], "10000N000000000000000000011000000001");
	ft_strdup_noM(game.map[8], "120000000000200000000000011100000001");
	ft_strdup_noM(game.map[9], "100000000000000010000000000000000001");
	ft_strdup_noM(game.map[10], "100000000000000010000000000002000001");
	ft_strdup_noM(game.map[11], "100000000000001100000000000000020001");
	ft_strdup_noM(game.map[12], "100000000001110000000010000200000001");
	ft_strdup_noM(game.map[13], "100011000200002000001100000000200001");
	ft_strdup_noM(game.map[14], "100001020002000000000000000000000001");
	ft_strdup_noM(game.map[15], "100001000000002001000000000000000001");
	ft_strdup_noM(game.map[16], "100000000200200000000000000010000001");
	ft_strdup_noM(game.map[17], "102002000000000110000000000000100001");
	ft_strdup_noM(game.map[18], "100000000002000000000000000000000001");
	ft_strdup_noM(game.map[19], "111111111111111111111111111111111111");
	game.x = 36;
	game.y = 20;
	game.xp = 4 * SIZE;
	game.yp = 9 * SIZE;
	ft_open_window(game);
	return (0);
}
