/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:47 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 10:42:50 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	copy_image_buffer3d(t_data *data, t_mi_img *image, int pos_y)
{
	int	pixel_bits;
	int	line_bits;
	int	endian;
	int	*colores;

	data->image_posy = pos_y;
	colores = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bits, &endian);
	buffer_helper(data, image, colores, line_bits);
}

void	buffer_helper(t_data *data, t_mi_img *image, int *color, int bits)
{
	int	x;
	int	y;
	int	suma;

	x = 0;
	y = 0;
	suma = 0;
	while (y < image->rows)
	{
		suma = y * bits;
		while (x < image->cols)
		{
			copy_pixel_buffer(data, x, y + data->image_posy, \
			mlx_get_color_value(data->mlx_ptr, color[suma + x]));
			mlx_get_color_value(data->mlx_ptr, color[suma + x]);
			x++;
		}
		x = 0;
		y++;
	}
}

void	option_check_camera_x(t_data *data)
{
	if (data->player.camera_x < 0)
		data->player.camera_x = 360 + data->player.camera_x;
	if (data->player.camera_x >= 360)
		data->player.camera_x = data->player.camera_x - 360;
}

void	debug_ray3d(t_data *data)
{
	int		hit;
	double	distance;
	double	separador;
	double	pos;

	pos = 0;
	hit = 0;
	separador = 1.0 / MAX_X_SIZE;
	option_check_camera_x(data);
	while (pos < FOV)
	{
		distance = 0 ;
		hit = 0;
		pos = pos + separador;
		while (hit == 0)
		{
			distance ++;
			hit = print_ray(data, distance, check_radian_angle(data, pos));
		}
		hit = 0;
	}
}

int	print_ray(t_data *data, double distance, double radianAngle)
{
	int	x;
	int	y;
	int	hit;

	x = (data->player.pos_x + distance) * -1 * cos(radianAngle);
	y = (data->player.pos_y + distance) * -1 * sin(radianAngle);
	if (y < 0)
		y = y * -1;
	if (x < 0)
		x = x * -1;
	copy_pixel_buffer(data, data->player.pos_x, data->player.pos_y, 0xFFFFFF);
	copy_pixel_buffer(data, data->player.pos_x, \
	data->player.pos_y + 1, 0xFF0000);
	copy_pixel_buffer(data, data->player.pos_x, \
	data->player.pos_y - 1, 0xFF00FF);
	copy_pixel_buffer(data, data->player.pos_x + 1, \
	data->player.pos_y, 0xFF0000);
	copy_pixel_buffer(data, data->player.pos_x - 1, \
	data->player.pos_y, 0xFF00FF);
	hit = data->check_pos[(int)x / WIDTH_3D_IMAGE][(int)y / WIDTH_3D_IMAGE];
	if (hit > 0)
		print_hit_color(data, hit, x, y);
	return (hit);
}
