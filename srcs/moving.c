/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:39:18 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 18:04:54 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	go_up(t_all *all)
{
	all->game->yp -= 1 / SIZE;
}

void	go_down(t_all *all)
{
	all->game->yp += 1 / SIZE;
}

void	go_left(t_all *all)
{
	all->game->xp -= 1 / SIZE;
}

void	go_right(t_all *all)
{
	all->game->xp += 1 / SIZE;
}
