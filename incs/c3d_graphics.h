/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:30:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/23 17:20:04 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

# include "c3d_game.h"

/// Renders the game to the window.
void	c3d_game_render(t_game *game);

/// Writes to the canvas, filling it with a raycasted image.
void	c3d_game_make_raycasted_image(t_game *game);

/// Renders the minimap.
void	c3d_game_render_minimap(t_game *game);

/// Renders the car overlay.
void	c3d_game_render_car(t_game *game);

void	c3d_render_confetti(t_game *game);

#endif
