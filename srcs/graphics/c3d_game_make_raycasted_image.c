/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_make_raycasted_image.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:59:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/17 08:51:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_graphics.h"
#include "c3d_types.h"
#include "c3d_settings.h"

inline static float	get_angle(float center, uint32_t column)
{
	float	percent;

	percent = (float)column / (float)C3D_WIDTH;
	return (center - C3D_FOV / 2.0f + C3D_FOV * percent);
}

inline static void set_pixel(t_img *img, uint32_t x, uint32_t y, t_rgb rgb)
{
	if (x >= img->width || y >= img->height)
		return ;
	img->data[x + y * img->width].rgb = rgb;
}

inline static void	make_column(
					t_game *game,
					t_img *wall_img,
					uint32_t column,
					uint32_t size)
{
	size_t	i;

	(void)wall_img;
	i = 0;
	if (size / 2 < C3D_HORIZON)
		while (i < C3D_HORIZON - size / 2)
			set_pixel(&game->canvas, column, i++, game->ceiling_color);
	while (i < C3D_HORIZON + (size + 1) / 2)
		set_pixel(&game->canvas, column, i++, (t_rgb){0xff, 0xff, 0xff});
	if (size / 2 < C3D_HORIZON)
		while (i < C3D_HEIGHT)
			set_pixel(&game->canvas, column, i++, game->floor_color);
}

inline static void	make_hit_column(t_game *game, t_hit *hit, size_t column)
{
	uint32_t	s;

	s = (uint32_t)((float)C3D_CUBE_HEIGHT / (hit->distance + 1.0f));
	if (hit->dir == C3D_DIR_NORTH)
		make_column(game, &game->north_texture, column, s);
	else if (hit->dir == C3D_DIR_EAST)
		make_column(game, &game->east_texture, column, s);
	else if (hit->dir == C3D_DIR_WEST)
		make_column(game, &game->west_texture, column, s);
	else if (hit->dir == C3D_DIR_SOUTH)
		make_column(game, &game->south_texture, column, s);
}

void	c3d_game_make_raycasted_image(t_game *game)
{
	uint32_t	i;
	t_hit		h;

	i = 0;
	while (i < game->canvas.width)
	{
		if (c3d_raycast(game->player.pos, get_angle(game->player.angle, i), &h))
			make_hit_column(game, &h, i);
		else
			make_column(game, NULL, i, 0);
		i++;
	}
}
