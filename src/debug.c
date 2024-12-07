/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:55:30 by incalero          #+#    #+#             */
/*   Updated: 2024/06/18 13:43:50 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	debug_map_definitions(t_data *data)
{
	if (ft_strlen(data->north_pic) == 0 || ft_strlen(data->south_pic) == 0 \
	|| ft_strlen(data->east_pic) == 0 || ft_strlen(data->west_pic) == 0)
		map_error(data, "Map definitions are missing", 1);
	if (data->floor_color.red == -1 || data->floor_color.green == -1 \
	|| data->floor_color.blue == -1)
		map_error(data, "Floor color is missing", 1);
	if (data->cell_color.red == -1 || data->cell_color.green == -1 \
	|| data->cell_color.blue == -1)
		map_error(data, "Cell color is missing", 1);
	if (data->rows == 0 || data->cols == 0)
		map_error(data, "Map rows or cols are missing", 1);
}

void	start_debug_cols_data(t_data *d)
{
	d->my_debug.i = 0;
	d->my_debug.j = 0;
	d->my_debug.x = 0;
	d->my_debug.y = 0;
	d->my_debug.posx = 0;
	d->my_debug.posy = 0;
	d->my_debug.hit = 0;
	d->my_debug.columna2 = 0;
	d->my_debug.linea20 = 0;
	d->my_debug.inicial_x = MAX_X_SIZE - (d-> cols * DEBUG2DMAP) - 50;
	d->my_debug.inicial_y = 0 + 50;
	d->my_debug.pos_jugador_x = 0;
	d->my_debug.pos_jugador_y = 0;
	d->my_debug.dist_correct = 0;
	d->my_debug.contador = 0;
	d->my_debug.grados = 66.0 / 1080.0;
	d->my_debug.rayangle = d->player.camera_x - 33;
	d->my_debug.distancia = 0;
	d->my_debug.linea2 = 0;
	d->my_debug.k = 0;
}

void	start_cols_data1(t_data *data)
{
	while (data->my_debug.contador < MAX_X_SIZE)
	{
		data->my_debug.hit = 0;
		if (data->my_debug.rayangle < 0)
			data->my_debug.rayangle += 360.0;
		data->my_debug.i = 0;
		data->my_debug.hit = 0;
		while (data->my_debug.hit == 0)
		{
			data->my_debug.x = data->player.pos_x + (int)(data->my_debug.i * \
			-1 * cos(data->my_debug.rayangle * M_PI / 180));
			data->my_debug.y = data->player.pos_y + (int)(data->my_debug.i * \
			-1 * sin(data->my_debug.rayangle * M_PI / 180));
			debug_cols_hit0(data);
		}
		data->my_debug.rayangle = data->my_debug.rayangle + \
		data->my_debug.grados;
		data->my_debug.contador++;
		data->my_debug.hit = 0;
	}
	data->my_debug.pos_jugador_x = data->my_debug.inicial_x \
	+ data->player.pos_x / DEBUG2DMAPSMALL;
	data->my_debug.pos_jugador_y = data->my_debug.inicial_y \
	+ data->player.pos_y / DEBUG2DMAPSMALL;
	debug_cols_hit1_3(data, 0, 0);
}

void	debug_cols(t_data *data)
{
	start_debug_cols_data(data);
	start_cols_data1(data);
	if (BONUS_RAY)
	{
		data->my_debug.contador = 0;
		data->my_debug.rayangle = data->player.camera_x - 33;
		data->my_debug.contador = 0;
		while (data->my_debug.contador < MAX_X_SIZE)
		{
			data->my_debug.hit = 0;
			if (data->my_debug.rayangle < 0)
				data->my_debug.rayangle += 360.0;
			data->my_debug.i = 0;
			data->my_debug.hit = 0;
			while (data->my_debug.hit == 0)
			{
				debug_cols_hit_0_1(data);
			}
			data->my_debug.rayangle = data->my_debug.rayangle + \
			data->my_debug.grados;
			data->my_debug.contador++;
			data->my_debug.hit = 0;
		}
	}
}
