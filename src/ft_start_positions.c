/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:53:43 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 16:44:53 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_animation_images3d(t_data *data, int x, int y)
{
	while (x < data->cols)
	{
		y = 0;
		while (y < data->rows)
		{
			if (data->player.pos_x == -1 && data->map[y][x] != '*' \
			&& data->map[y][x] != '1' && data->map[y][x] != '0')
			{
				data->player.pos_x = x * data->player_img->cols + \
				data->player_img->cols / 2;
				data->player.pos_y = y * data->player_img->rows + \
				data->player_img->rows / 2;
				if (data->map[y][x] == 'N')
					data->player.camera_x = 90;
				else if (data->map[y][x] == 'S')
					data->player.camera_x = 270;
				else if (data->map[y][x] == 'W')
					data->player.camera_x = 0;
				else if (data->map[y][x] == 'E')
					data->player.camera_x = 180;
			}
			y++;
		}
		x++;
	}
}
