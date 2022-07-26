/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:17 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 14:53:46 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SETTINGS_H
# define C3D_SETTINGS_H

/// The width, in pixels, of the game.
# define C3D_WIDTH 160
/// The height, in pixels, of the game.
# define C3D_HEIGHT 90

/// The number of physical pixel per pixel of the game.
# define C3D_PIXEL_SIZE 6

/// The angle of view.
# define C3D_FOV 90.0f
/// The height of the horizon.
# define C3D_HORIZON 45
/// The height of a cube that is just on the player.
# define C3D_CUBE_HEIGHT 90

/// The distance between the center of the minimap and the edge of the screen.
# define C3D_MINIMAP_OFFSET 30
/// The size of each pixel of the minimap.
# define C3D_MINIMAP_SCALE 1
/// The squared radius of the minimap.
# define C3D_MINIMAP_RADIUS 25

#endif
