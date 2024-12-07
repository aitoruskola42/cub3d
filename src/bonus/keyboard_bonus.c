/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:09:58 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/17 13:24:50 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 115)
		data->down = 1;
	if (keysym == 119)
		data->up = 1;
	if (keysym == 97)
		data->left = 1;
	if (keysym == 100)
		data->right = 1;
	if (keysym == 65361)
		data->rotate_left = 1;
	if (keysym == 65363)
		data->rotate_right = 1;
	if (keysym == 65307)
		map_error(data, "Esc key exit", 0);
	return (1);
}

int	ft_key_hook_release(int keysym, t_data *data)
{
	if (keysym == 115)
		data->down = 0;
	if (keysym == 119)
		data->up = 0;
	if (keysym == 97)
		data->left = 0;
	if (keysym == 100)
		data->right = 0;
	if (keysym == 65361)
		data->rotate_left = 0;
	if (keysym == 65363)
		data->rotate_right = 0;
	return (1);
}

int	move_finish(t_data *data)
{
	int	dont_move;

	if (data->map[(data->player.pos_y + COLISION_DETECTOR) / \
	WIDTH_3D_IMAGE][data->player.pos_x / WIDTH_3D_IMAGE] == 49)
		dont_move = 1;
	if (data->map[(data->player.pos_y - COLISION_DETECTOR) / \
	WIDTH_3D_IMAGE][data->player.pos_x / WIDTH_3D_IMAGE] == 49)
		dont_move = 1;
	if (data->map[data->player.pos_y / \
	WIDTH_3D_IMAGE][(data->player.pos_x - \
	COLISION_DETECTOR) / WIDTH_3D_IMAGE] == 49)
		dont_move = 1;
	if (data->map[data->player.pos_y / \
	WIDTH_3D_IMAGE][(data->player.pos_x + \
	COLISION_DETECTOR) / WIDTH_3D_IMAGE] == 49)
		dont_move = 1;
	if (dont_move == 1)
	{
		data->player.pos_x = data->player.previous_pos_x;
		data->player.pos_y = data->player.previous_pos_y;
	}
	return (1);
}
