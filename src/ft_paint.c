/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:06:47 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/13 13:13:01 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_pixel_image(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->mlx_ptr, data->img_copy_ptr, x, y, \
	mlx_get_color_value(data->mlx_ptr, color));
}

void	print_pixel(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, \
	mlx_get_color_value(data->mlx_ptr, color));
}

void	print_image_from_memory(t_data *data, t_mi_img *image)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, 0, 0);
}

void	print_text_on_screen(t_data *data, char *text, int x, int y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF, text);
}

void	copy_pixel_buffer(t_data *data, int x, int y, int color)
{
	int		pixel;
	int		line_bits;
	int		pixel_bits;
	int		endian;
	char	*destino;

	if (x < 0 || x > data->window_width || y < 0 || y > data->window_height)
		return ;
	destino = mlx_get_data_addr(data->img_copy_ptr, \
	&pixel_bits, &line_bits, &endian);
	pixel = (y * line_bits) + (x * 4);
	destino[pixel + 0] = (color) & 0xFF;
	destino[pixel + 1] = (color >> 8) & 0xFF;
	destino[pixel + 2] = (color >> 16) & 0xFF;
	destino[pixel + 3] = (color >> 24);
}
