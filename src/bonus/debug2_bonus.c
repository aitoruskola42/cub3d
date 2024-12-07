/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:54:26 by incalero          #+#    #+#             */
/*   Updated: 2024/06/18 13:37:17 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	debug_cols_hit0(t_data *data)
{
	if (data->map[data->my_debug.y / 300][data->my_debug.x / 300] == '1')
	{
		data->my_debug.posx = data->my_debug.inicial_x + \
		data->my_debug.i / DEBUG2DMAPSMALL;
		data->my_debug.posy = data->my_debug.inicial_y + \
		data->my_debug.i / DEBUG2DMAPSMALL;
		data->my_debug.hit = 1;
	}
	else
		parse_hit_out(data);
	if (data->my_debug.hit == 1)
	{
		debug_cols_hit1_1(data);
		return ;
	}
	else
	{
		data->my_debug.posx = data->my_debug.inicial_x + \
		data->my_debug.x / DEBUG2DMAPSMALL;
		data->my_debug.posy = data->my_debug.inicial_y + \
		data->my_debug.y / DEBUG2DMAPSMALL;
	}
	debug_cols_hit_patch(data);
}

void	debug_cols_hit1_1(t_data *data)
{
	data->my_debug.posx = data->my_debug.inicial_x + \
	data->my_debug.x / DEBUG2DMAPSMALL;
	data->my_debug.posy = data->my_debug.inicial_y + \
	data->my_debug.y / DEBUG2DMAPSMALL;
	data->my_debug.distancia = calculate_distance(data, \
	data->my_debug.x, data->my_debug.y);
	if (data->my_debug.distancia < 0)
		data->my_debug.distancia = data->my_debug.distancia * -1;
	if (data->my_debug.rayangle <= data->player.camera_x)
		data->my_debug.dist_correct = data->my_debug.distancia * \
		(sin((data->my_debug.rayangle - \
		(data->player.camera_x - 90)) * (M_PI / 180)));
	else
		data->my_debug.dist_correct = data->my_debug.distancia * \
		(sin((((data->player.camera_x + 90) - \
		data->my_debug.rayangle) *(M_PI / 180))));
	data->altitud = calculate_height(data->my_debug.dist_correct);
	debug_cols_hit1_1_1(data);
}

void	debug_cols_hit1_1_1(t_data *data)
{
	if (data->my_debug.y % 300 == 0)
		get_pixel3(data, data->north_cols, \
		data->my_debug.contador, data->my_debug.x);
	else if (data->my_debug.x % 300 == 0)
		get_pixel3(data, data->east_cols, \
		data->my_debug.contador, data->my_debug.y);
	else if (data->my_debug.y % 300 == 299)
		get_pixel3(data, data->south_cols, \
		data->my_debug.contador, data->my_debug.x);
	else if (data->my_debug.x % 300 == 299)
		get_pixel3(data, data->west_cols, \
		data->my_debug.contador, data->my_debug.y);
	else
		map_error(data, "Error map colisions", 1);
	if (BONUS)
		copy_pixel_buffer(data, data->my_debug.posx, \
		data->my_debug.posy, COLOR_RAY_COLLISION);
	data->my_debug.i = 0;
}

void	debug_cols_bucle_2(t_data *data)
{
	data->my_debug.j = 0;
	while (data->my_debug.j < DEBUG2DMAP)
	{
		if (data->map[data->my_debug.linea2][data->my_debug.columna2] \
		== '1')
			copy_pixel_buffer(data, data->my_debug.x \
			+ data->my_debug.k, data->my_debug.y + \
			data->my_debug.j, COLOR_RAY_WALL);
		data->my_debug.j++;
	}
	data->my_debug.k++;
}

void	debug_cols_hit1_2(t_data *data)
{
	while (data->my_debug.columna2 <= data->cols)
	{
		data->my_debug.linea2 = 1;
		while (data->my_debug.linea2 <= data->rows)
		{
			data->my_debug.k = 0;
			data->my_debug.x = data->my_debug.inicial_x + \
			data->my_debug.columna2 * DEBUG2DMAP;
			data->my_debug.y = data->my_debug.inicial_y + \
			data->my_debug.linea2 * DEBUG2DMAP;
			while (data->my_debug.k < DEBUG2DMAP)
			{
				debug_cols_bucle_2(data);
			}
			data->my_debug.linea2++;
		}
		data->my_debug.columna2++;
	}
}
