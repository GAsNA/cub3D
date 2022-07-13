/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:39:18 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/13 16:01:47 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	go_up(t_all *all)
{
	draw_line_horizontal(all->img, all->game->xp, all->game->yp + SIZE - 1, WHITE);
	all->game->yp -= 1;
	draw_line_horizontal(all->img, all->game->xp, all->game->yp, RED);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img->img, 0, 0);
}

void	go_down(t_all *all)
{
	draw_line_horizontal(all->img, all->game->xp, all->game->yp, WHITE);
	all->game->yp += 1;
	draw_line_horizontal(all->img, all->game->xp, all->game->yp + SIZE - 1, RED);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img->img, 0, 0);
}

void	go_left(t_all *all)
{
	draw_line_vertical(all->img, all->game->xp + SIZE - 1, all->game->yp, WHITE);
	all->game->xp -= 1;
	draw_line_vertical(all->img, all->game->xp, all->game->yp, RED);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img->img, 0, 0);
}

void	go_right(t_all *all)
{
	draw_line_vertical(all->img, all->game->xp, all->game->yp, WHITE);
	all->game->xp += 1;
	draw_line_vertical(all->img, all->game->xp + SIZE - 1, all->game->yp, RED);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, all->img->img, 0, 0);
}
