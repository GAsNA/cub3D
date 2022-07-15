/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_img_load_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:26:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/15 23:40:39 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"
#include "mlx.h"

static void	from_raw(void *mlx_ptr, void *img, uint64_t size, t_img *result)
{
	int		bits_per_pixel;
	int		big_endian;
	int		line_size;
	char	*addr;

	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_size, &big_endian);
	if (bits_per_pixel != 32 || (uint32_t)line_size != (uint32_t)size * 4)
	{
		mlx_destroy_image(mlx_ptr, img);
		ft_unwind_panic("the current X server is not supported");
	}
	result->data = (t_rgba *)addr;
	result->width = (uint32_t)size;
	result->height = size >> 32;
	result->raw = img;
}

void	c3d_img_load_file(void *mlx_ptr, const char *filename, t_img *result)
{
	int		width;
	int		height;
	void	*raw;

	raw = mlx_xpm_file_to_image(mlx_ptr, (char *)filename, &width, &height);
	if (!raw)
		ft_unwind_panic("failed to load `{s?}`", filename);
	from_raw(mlx_ptr, raw, (uint64_t)width | ((uint64_t)height << 32), result);
}

void	c3d_img_create(
			void *mlx_ptr,
			uint32_t width,
			uint32_t height,
			t_img *result)
{
	void	*raw;

	raw = mlx_new_image(mlx_ptr, width, height);
	if (!raw)
		ft_unwind_panic("failed to create an image");
	from_raw(mlx_ptr, raw, (uint64_t)width | ((uint64_t)height << 32), result);
}
