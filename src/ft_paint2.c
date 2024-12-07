/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:12:33 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/13 13:12:55 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	copy_image_buffer_cols(t_data *data, \
t_mi_img *image, int (*mapa_cols)[300])
{
	int		*colores;
	int		color;

	colores = (int *)mlx_get_data_addr(image, &data->pixel_bits, \
	&data->line_bits, &data->endian);
	data->i = 0;
	data->j = 0;
	while (data->j < image->rows)
	{
		while (data->i < image->cols)
		{
			color = mlx_get_color_value(data->mlx_ptr, \
			colores[data->j * data->line_bits + data->i]);
			mapa_cols[data->i][data->j] = color;
			copy_image_buffer_cols2(data, data->i, data->j, color);
			data->i++;
		}
		data->i = 0;
		data->j++;
	}
}

void	copy_image_buffer_cols2(t_data *data, int x, int y, int color)
{
	int		pixel;
	char	*destino;

	destino = mlx_get_data_addr(data->img_copy_ptr, &data->pixel_bits2, \
	&data->line_bits2, &data->endian);
	pixel = (y * data->line_bits2 + WIDTH_3D_IMAGE * data->line_bits2) \
	+ ((WIDTH_3D_IMAGE + x) * 4);
	destino[pixel + 0] = (color) & 0xFF;
	destino[pixel + 1] = (color >> 8) & 0xFF;
	destino[pixel + 2] = (color >> 16) & 0xFF;
	destino[pixel + 3] = (color >> 24);
}
