/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options3d2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:50:27 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 14:50:32 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	check_radian_angle(t_data *data, double pos)
{
	double	radian_angle;
	double	angulo_mirada;

	angulo_mirada = data->player.camera_x - 33;
	if (angulo_mirada < 0)
		angulo_mirada += 360.0;
	radian_angle = (((double)angulo_mirada + pos));
	if (radian_angle < 0)
		radian_angle += 360.0;
	return (radian_angle);
}

void	print_hit_color(t_data *data, int resultado, int x, int y)
{
	double	wall_distance;

	wall_distance = sqrt(pow(x - data->player.pos_x, 2) + \
	pow(y - data->player.pos_y, 2));
	if (wall_distance < 0)
		wall_distance = wall_distance * -1;
	resultado = data->check_pos[(int)x][(int)y];
	if (resultado == 2)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FF00);
	if (resultado == 3)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
	if (resultado == 4)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x0000FF);
	if (resultado == 5)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFF00);
}
