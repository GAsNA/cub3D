/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_make_raycasted_image.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:59:24 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/20 12:52:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_graphics.h"
#include "c3d_types.h"
#include "c3d_settings.h"
#include "c3d_raycast.h"

inline static void	set_pixel(t_img *img, uint32_t x, uint32_t y, t_rgb rgb)
{
	if (x >= img->width || y >= img->height)
		return ;
	img->data[x + y * img->width].rgb = rgb;
}

inline static t_rgb	sample_image(t_img *img, float x, float y)
{
	const uint32_t	_x = (uint32_t)(x * (float)img->width);
	const uint32_t	_y = (uint32_t)(y * (float)img->height);

	if (_x >= img->width || _y >= img->height)
		return ((t_rgb){0x00, 0x00, 0x00});
	else
		return (img->data[_x + _y * img->width].rgb);
}

inline static void	make_column(
					t_game *game,
					t_img *img,
					uint32_t *column_start_end,
					float img_x)
{
	const uint32_t	column = column_start_end[0];
	int32_t			true_start = (int32_t)column_start_end[1];
	const float		size = (float)((int32_t)column_start_end[2] - (int32_t)column_start_end[1]);
	size_t			i;

	if ((int32_t)column_start_end[1] < 0)
			column_start_end[1] = 0;
	if (column_start_end[2] > C3D_HEIGHT)
		column_start_end[2] = C3D_HEIGHT;
	i = 0;
	while (i < C3D_HORIZON - C3D_LOOK_V_AMOUNT * game->player.look.y)
		set_pixel(&game->canvas, column, i++, game->ceiling_color);
	while (i < C3D_HEIGHT)
		set_pixel(&game->canvas, column, i++, game->floor_color);
	i = (size_t)column_start_end[1] - 1;
	if (img)
		while (++i < (size_t)column_start_end[2])
			set_pixel(&game->canvas, column, i, sample_image(img, img_x,
				(float)(i - true_start) / size));
}

inline static void	make_hit_column(t_game *game, t_hit *hit, size_t column)
{
	const float	percent = 0.5 / hit->distance;
	uint32_t	column_start_end[3];

	column_start_end[0] = column;
	column_start_end[1] = C3D_HORIZON - C3D_LOOK_V_AMOUNT * game->player.look.y
		- (int32_t)(percent * (float)C3D_HEIGHT);
	column_start_end[2] = C3D_HORIZON - C3D_LOOK_V_AMOUNT * game->player.look.y + (int32_t)(percent * (float)C3D_HEIGHT);
	if (hit->dir == C3D_DIR_NORTH)
		make_column(game, &game->north_texture, column_start_end, hit->tex_x);
	else if (hit->dir == C3D_DIR_EAST)
		make_column(game, &game->east_texture, column_start_end, hit->tex_x);
	else if (hit->dir == C3D_DIR_WEST)
		make_column(game, &game->west_texture, column_start_end, hit->tex_x);
	else if (hit->dir == C3D_DIR_SOUTH)
		make_column(game, &game->south_texture, column_start_end, hit->tex_x);
}

void	c3d_game_make_raycasted_image(t_game *game)
{
	uint32_t	i[3];
	t_ray		r;
	t_hit		h;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < game->canvas.width)
	{
		c3d_create_ray(&r, game->player.pos, game->player.angle + game->player.look.x * C3D_LOOK_H_ANGLE, i[0]);
		if (c3d_cast_ray(&r, game, &h))
			make_hit_column(game, &h, i[0]);
		else
			make_column(game, NULL, i, 0.0);
		i[0]++;
	}
}
