/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alturas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:54:37 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/18 12:28:34 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	calculate_distance(t_data *data, int x, int y)
{
	int		delta_x;
	int		delta_y;
	double	distancia;	

	delta_x = x - data->player.pos_x;
	delta_y = y - data->player.pos_y;
	distancia = sqrt(delta_x * delta_x + delta_y * delta_y);
	if (distancia < 0)
		distancia = distancia * -1;
	return (distancia);
}

int	calculate_height(int distancia)
{
	return ((920 * 300 / distancia));
}

void	get_pixel3(t_data *data, int (*mapa_cols)[300], int cont, int hit_pos)
{
	int	color;
	int	start_height;
	int	contador;
	int	posy;
	int	factor_y;

	contador = 0;
	posy = 0;
	if (cont < 0)
		cont = 0;
	start_height = ((MAX_Y_SIZE) / 2) - (data->altitud / 2);
	while (contador < data->altitud)
	{
		factor_y = (contador * WIDTH_3D_IMAGE) / data->altitud;
		posy = factor_y;
		color = mapa_cols[hit_pos % 300][posy];
		copy_pixel_buffer(data, cont, start_height + contador, color);
		contador ++;
	}
}
