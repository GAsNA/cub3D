/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:17 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/27 11:43:57 by nmathieu         ###   ########.fr       */
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
# define C3D_MINIMAP_OFFSET 25
/// The size of each pixel of the minimap.
# define C3D_MINIMAP_SCALE 1.0f
/// The squared radius of the minimap.
# define C3D_MINIMAP_RADIUS 20

/// The speed at which the game is played.
/// This value can be adjusted if the computer is too fast.
# define C3D_DELTA_TIME 0.2f

/// The force constantly applied to the player, dragging its velocity down.
# define C3D_PLAYER_DRAG 0.02f
/// The force applied to the player when they wish to accelerate.
# define C3D_PLAYER_FORCE 0.1f
/// The angle added to the player each frame when they want to turn.
# define C3D_PLAYER_TURN 0.03f
/// The force of the player's brakes.
# define C3D_PLAYER_BREAK 0.05f
/// The force applied to the player when they wish to go backward.
# define C3D_PLAYER_BW_FORCE 0.02f

#endif