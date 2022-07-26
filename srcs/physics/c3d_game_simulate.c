/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_simulate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:28:02 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 15:45:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_physics.h"
#include "c3d_game.h"

void	c3d_game_simulate(t_game *self)
{
	c3d_game_move_player(self);
}
