/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:01 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 11:35:07 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_pixel2(t_data *data, int **mapa_cols, int cont, int altitud)
{
	int	color;
	int	start_height;
	int	contador;
	int	factor_y;

	contador = 0;
	if (cont < 0)
		cont = 0;
	start_height = ((MAX_Y_SIZE) / 2) - (altitud / 2);
	while (contador < altitud && contador < MAX_Y_SIZE)
	{
		factor_y = (contador * WIDTH_3D_IMAGE) / altitud;
		color = mapa_cols[cont % WIDTH_3D_IMAGE][factor_y];
		copy_pixel_buffer(data, cont, start_height + contador, color);
		contador ++;
	}
}
