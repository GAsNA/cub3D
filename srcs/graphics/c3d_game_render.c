/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:37:57 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/26 15:11:27 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "c3d_graphics.h"
#include "mlx.h"
#include "libft.h"

void	c3d_game_render(t_game *game)
{
	//c3d_game_make_raycasted_image(game);
	ft_mem_set(game->canvas.data, 0x00, game->canvas.width * game->canvas.height * sizeof(t_rgba));
	c3d_game_render_minimap(game);
	c3d_game_scale_canvas(game);
	mlx_put_image_to_window(game->mlx, game->win, game->final_canvas.raw, 0, 0);
}
