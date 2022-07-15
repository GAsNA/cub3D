/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:30:07 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 23:54:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

# include "c3d_game.h"

/// Copies the content of `canvas` to `final_canvas`, upscaling it properly.
void	c3d_game_scale_canvas(t_game *game);

/// Renders the game to the window.
void	c3d_game_render(t_game *game);

#endif
