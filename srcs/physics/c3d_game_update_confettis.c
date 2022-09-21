/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_update_confettis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:54:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 11:24:37 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_settings.h"

static void	update_confetti(t_confetti *self)
{
	t_vec2	force;

	force = (t_vec2){0.0f, 0.0f};
	force.y += 2.0f;
	force.x -= self->vel.x * 0.1f;
	force.y -= self->vel.y * 0.1f;
	self->vel.x += force.x * C3D_DELTA_TIME;
	self->vel.y += force.y * C3D_DELTA_TIME;
	self->pos.x += self->vel.x * C3D_DELTA_TIME;
	self->pos.y += self->vel.y * C3D_DELTA_TIME;
}

void	c3d_game_update_confettis(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->confetti_count)
	{
		update_confetti(&game->confettis[i]);
		i++;
	}
}
