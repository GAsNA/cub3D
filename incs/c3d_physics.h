/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_physics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:28:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 11:10:16 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_PHYSICS_H
# define C3D_PHYSICS_H

# include "c3d_game.h"

/// Simulates the game world.
void	c3d_game_simulate(t_game *self);

/// Moves the player.
void	c3d_game_move_player(t_game *game);

bool	c3d_player_touches(t_game *game, t_tile tile);

void	c3d_set_line(t_game *game, bool line);
void    c3d_game_update_line(t_game *game);
void	c3d_game_update_confettis(t_game *game);

#endif
