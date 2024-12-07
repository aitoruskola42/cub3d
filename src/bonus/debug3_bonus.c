/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:54:51 by incalero          #+#    #+#             */
/*   Updated: 2024/06/18 13:44:12 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	debug_cols_hit_0_1(t_data *data)
{
	data->my_debug.x = data->player.pos_x + (int)(data->my_debug.i \
	* -1 * cos(data->my_debug.rayangle * M_PI / 180));
	data->my_debug.y = data->player.pos_y + (int)(data->my_debug.i \
	* -1 * sin(data->my_debug.rayangle * M_PI / 180));
	if (data->map[data->my_debug.y / 300][data->my_debug.x / 300] == '1')
	{
		data->my_debug.posx = data->my_debug.inicial_x + \
		data->my_debug.i / DEBUG2DMAPSMALL;
		data->my_debug.posy = data->my_debug.inicial_y + \
		data->my_debug.i / DEBUG2DMAPSMALL;
		data->my_debug.hit = 1;
	}
	else
	{
		if (data->map[data->my_debug.y / 300][data->my_debug.x / 300] == '*')
			data->my_debug.hit = 1;
		else
			data->my_debug.hit = 0;
	}
	debug_cols_hit_0_2(data);
	data->my_debug.i++;
}

void	debug_cols_hit_0_2(t_data *data)
{
	if (data->my_debug.hit == 1)
	{
		data->my_debug.posx = data->my_debug.inicial_x + \
		data->my_debug.x / DEBUG2DMAPSMALL;
		data->my_debug.posy = data->my_debug.inicial_y + \
		data->my_debug.y / DEBUG2DMAPSMALL;
		data->my_debug.distancia = calculate_distance(data, \
		data->my_debug.x, data->my_debug.y);
		if (BONUS && (data->my_debug.contador == 0))
			copy_pixel_buffer(data, data->my_debug.posx, \
			data->my_debug.posy, COLOR_RAY_COLLISION);
		data->my_debug.i = 0;
		return ;
	}
	else
	{
		data->my_debug.posx = data->my_debug.inicial_x \
		+ data->my_debug.x / DEBUG2DMAPSMALL;
		data->my_debug.posy = data->my_debug.inicial_y \
		+ data->my_debug.y / DEBUG2DMAPSMALL;
		if (BONUS)
			copy_pixel_buffer(data, data->my_debug.posx, \
		data->my_debug.posy, COLOR_RAY);
	}
}

void	debug_cols_hit1_3(t_data *data, int p, int o)
{
	data->my_debug.posx = data->my_debug.pos_jugador_x;
	data->my_debug.posy = data->my_debug.pos_jugador_y;
	if (BONUS)
	{
		debug_cols_hit1_2(data);
		while (p < 4)
		{
			o = 0;
			while (o < 4)
			{
				copy_pixel_buffer(data, data->my_debug.posx, \
				data->my_debug.posy, COLOR_RAY_PLAYER);
				copy_pixel_buffer(data, (data->my_debug.posx + p), \
				(data->my_debug.posy - o), COLOR_RAY_PLAYER);
				copy_pixel_buffer(data, (data->my_debug.posx + p), \
				(data->my_debug.posy + o), COLOR_RAY_PLAYER);
				copy_pixel_buffer(data, (data->my_debug.posx - p), \
				(data->my_debug.posy - o), COLOR_RAY_PLAYER);
				copy_pixel_buffer(data, (data->my_debug.posx - p), \
				(data->my_debug.posy + o), COLOR_RAY_PLAYER);
				o ++;
			}
			p++;
		}
	}
}

void	parse_hit_out(t_data *data)
{
	if (data->map[data->my_debug.y / 300][data->my_debug.x / 300] == '*')
		data->my_debug.hit = 1;
	else
		data->my_debug.hit = 0;
}

void	debug_cols_hit_patch(t_data *data)
{
	data->paso_x = data->my_debug.x % 300;
	data->paso_y = data->my_debug.y % 300;
	if (data->paso_x == 0 || data->paso_y == 0 || \
	data->paso_x == 299 || data->paso_y == 299)
		data->my_debug.i++;
	else
	{
		data->movimiento_x = 0;
		data->movimiento_y = 0;
		if (data->paso_x >= 150)
			data->movimiento_x = (300 - data->paso_x);
		else
			data->movimiento_x = data->paso_x;
		if (data->paso_y >= 150)
			data->movimiento_y = (300 - data->paso_y);
		else
			data->movimiento_y = (data->paso_y);
		if (data->movimiento_x > data->movimiento_y)
			data->my_debug.i = data->my_debug.i + data->movimiento_y;
		else
			data->my_debug.i = data->my_debug.i + data->movimiento_x;
	}
}
