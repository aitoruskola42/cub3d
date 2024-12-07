/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:47:34 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 15:49:04 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_map_player(t_data *data, int x)
{
	int	y;
	int	counter;

	counter = 0;
	while (x < data->rows)
	{
		y = 0;
		while (y < data->cols)
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
			|| data->map[x][y] == 'W' || data->map[x][y] == 'E')
			{
				counter++;
				data->player.pos_x = x * data->res + data->res / 2;
				data->player.pos_y = y * data->res + data->res / 2;
				data->player.square_x = y;
				data->player.square_y = x;
			}
			y++;
		}
		x++;
	}
	if (counter != 1)
		map_error(data, "Num Players error", 1);
}
