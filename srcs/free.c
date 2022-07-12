/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:32:07 by rleseur           #+#    #+#             */
/*   Updated: 2022/07/12 18:36:04 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	all_free(t_all *all)
{
	mlx_loop_end(all->vars->mlx);
	mlx_destroy_image(all->vars->mlx, all->img->img);
	mlx_destroy_window(all->vars->mlx, all->vars->win);
	mlx_destroy_display(all->vars->mlx);
	free(all->vars->mlx);
}
