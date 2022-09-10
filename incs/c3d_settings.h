/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:17 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/09 19:07:45 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SETTINGS_H
# define C3D_SETTINGS_H

/// The width, in pixels, of the game.
# define C3D_WIDTH 600
/// The height, in pixels, of the game.
# define C3D_HEIGHT 300

/// The number of physical pixel per pixel of the game.
# define C3D_PIXEL_SIZE 3

/// The height of the horizon.
# define C3D_HORIZON 150

/// The distance between the center of the minimap and the edge of the screen.
# define C3D_MINIMAP_OFFSET 100
/// The size of each pixel of the minimap.
# define C3D_MINIMAP_SCALE 2.0f
/// The squared radius of the minimap.
# define C3D_MINIMAP_RADIUS 80

/// The speed at which the game is played.
/// This value can be adjusted if the computer is too fast.
# define C3D_DELTA_TIME 0.2f

/// The force constantly applied to the player, dragging its velocity down.
# define C3D_PLAYER_DRAG 0.02f
/// The force applied to the player when they wish to accelerate.
# define C3D_PLAYER_FORCE 0.03f
/// The angle added to the player each frame when they want to turn.
# define C3D_PLAYER_TURN 0.03f
/// The force of the player's brakes.
# define C3D_PLAYER_BREAK 0.05f
/// The force applied to the player when they wish to go backward.
# define C3D_PLAYER_BW_FORCE 0.02f

# define C3D_CAMERA_PLANE 2.0f

#endif
