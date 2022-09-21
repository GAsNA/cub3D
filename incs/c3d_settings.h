/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:17 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 11:26:53 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SETTINGS_H
# define C3D_SETTINGS_H

/// The width, in pixels, of the game.
# define C3D_WIDTH 800
/// The height, in pixels, of the game.
# define C3D_HEIGHT 600

/// The height of the horizon.
# define C3D_HORIZON 300

/// The distance between the center of the minimap and the edge of the screen.
# define C3D_MINIMAP_OFFSET 120
/// The size of each pixel of the minimap.
# define C3D_MINIMAP_SCALE 3.0f
/// The squared radius of the minimap.
# define C3D_MINIMAP_RADIUS 100

/// The diameter of the stiring wheel, in pixels.
# define C3D_WHEEL_SIZE 300
/// A factor to make the wheel turn.
# define C3D_WHEEL_FACTOR 5.0f

/// The speed at which the game is played.
/// This value can be adjusted if the computer is too fast.
# define C3D_DELTA_TIME 0.4f
// # define C3D_DELTA_TIME 0.8f

/// The force constantly applied to the player, dragging its velocity down.
# define C3D_PLAYER_DRAG 0.02f
/// The force applied to the player when they wish to accelerate.
# define C3D_PLAYER_FORCE 0.03f
/// The angle added to the player each frame when they want to turn.
# define C3D_PLAYER_TURN 0.1f
// # define C3D_PLAYER_TURN 0.2f
/// The amount of "time" the player takes to turn the wheel.
# define C3D_PLAYER_TURN_TIME 0.06f
/// The force of the player's brakes.
# define C3D_PLAYER_BREAK 0.1f
/// The force applied to the player when they wish to go backward.
# define C3D_PLAYER_BW_FORCE 0.02f

/// The "speed" at which the player looks when using the array keys.
# define C3D_LOOK_SPEED 0.05f
/// The amount of movement when looking with the mouse.
# define C3D_LOOK_MOUSE_H 80.0f
# define C3D_LOOK_MOUSE_V 40.0f
/// The amount of distance the player can look up/down.
# define C3D_LOOK_H_ANGLE 0.3f
/// The amount of distance the player can look left/right.
# define C3D_LOOK_V_AMOUNT 150.0f

# define C3D_COLLIDER 0.3f

/// The size of the camera plane.
///
/// This value roughly matches the effective Field Of View.
# define C3D_CAMERA_PLANE 0.9f

# define C3D_CONFETTI_MAX 512U

#endif
