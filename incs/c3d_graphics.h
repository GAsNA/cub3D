/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:30:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 14:18:12 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

# include "c3d_game.h"

/// Copies the content of `canvas` to `final_canvas`, upscaling it properly.
void	c3d_game_scale_canvas(t_game *game);

/// Renders the game to the window.
void	c3d_game_render(t_game *game);

/// Writes to the canvas, filling it with a raycasted image.
void	c3d_game_make_raycasted_image(t_game *game);

/// Renders the minimap.
void    c3d_game_render_minimap(t_game *game);

// Lauches a ray from `origin` at angle `angle`. If it hits a wall, `true` is
// returned and `result` contains information about the hit. Otherwise, `false`
// is returned.
bool	c3d_raycast(t_vec2 origin, float angle, t_hit *result);

#endif
