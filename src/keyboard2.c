/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:50:47 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/27 12:53:41 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	make_move(t_data *data, double cosValue, double sinValue)
{
	int	resultado;

	data->player_x_pos_check = data->player.pos_x ;
	data->player_y_pos_check = data->player.pos_y ;
	data->player.previous_pos_x = data->player.pos_x;
	data->player.previous_pos_y = data->player.pos_y;
	resultado = data->map[data->player_y_pos_check / \
	WIDTH_3D_IMAGE][data->player_x_pos_check / WIDTH_3D_IMAGE];
	if (data->player.pos_y != -1 && data->player.pos_x != -1)
	{
		if (resultado == 49 || data->player.pos_x < 300 + \
		PLAYER_MOVE_SPEED * 1.5 || data->player.pos_y < 300 + \
		PLAYER_MOVE_SPEED * 1.5 || data->player.pos_x > \
		(data->cols - 1) * 300 || data->player.pos_y > \
		(data->rows - 1) * 300)
		{
			data->player.pos_x = data->player.previous_pos_x;
			data->player.pos_y = data->player.previous_pos_y;
		}
	}
	make_move1(data, cosValue, sinValue);
	make_move2(data);
}

void	make_move1_b(t_data *data, double cosValue, double sinValue)
{
	if (data->left == 1)
	{
		data->player.pos_x -= (PLAYER_MOVE_SPEED * sinValue);
		data->player.pos_y += (PLAYER_MOVE_SPEED * cosValue);
		data->player_x_pos_check -= (data->colision_check * cosValue);
		data->player_y_pos_check -= (data->colision_check * sinValue);
	}
	if (data->right == 1)
	{
		data->player.pos_x += (PLAYER_MOVE_SPEED * sinValue);
		data->player.pos_y -= (PLAYER_MOVE_SPEED * cosValue);
		data->player_x_pos_check += (data->colision_check * cosValue);
		data->player_y_pos_check += (data->colision_check * sinValue);
	}
}

void	make_move1(t_data *data, double cosValue, double sinValue)
{
	if (data->down == 1)
	{
		data->player.pos_x += (PLAYER_MOVE_SPEED * cosValue);
		data->player.pos_y += (PLAYER_MOVE_SPEED * sinValue);
		data->player_x_pos_check += (data->colision_check * cosValue);
		data->player_y_pos_check += (data->colision_check * sinValue);
	}
	if (data->up == 1)
	{
		data->player.pos_x -= (PLAYER_MOVE_SPEED * cosValue);
		data->player.pos_y -= (PLAYER_MOVE_SPEED * sinValue);
		data->player_x_pos_check -= (data->colision_check * cosValue);
		data->player_y_pos_check -= (data->colision_check * sinValue);
	}
	make_move1_b(data, cosValue, sinValue);
}

void	make_move2(t_data *data)
{
	if (data->rotate_left == 1)
	{
		if (data->player.camera_x == 0)
			data->player.camera_x = 360;
		if (data->player.camera_x == CAMERA_MOVE_SPEED)
			data->player.camera_x = 360;
		else
			data->player.camera_x -= CAMERA_MOVE_SPEED;
		if (data->player.camera_x == 360)
			data->player.camera_x = 0;
	}
	if (data->rotate_right == 1)
	{
		if (data->player.camera_x == 360)
			data->player.camera_x = CAMERA_MOVE_SPEED ;
		else
			data->player.camera_x += CAMERA_MOVE_SPEED;
		if (data->player.camera_x == 360)
			data->player.camera_x = 0;
	}
	make_move3(data);
}

void	make_move3(t_data *data)
{
	int	resultado;

	resultado = data->map[data->player.pos_y / \
	WIDTH_3D_IMAGE][data->player.pos_x / WIDTH_3D_IMAGE];
	if (data->player.pos_y != -1 && data->player.pos_x != -1)
	{
		if (resultado == 49 || data->player.pos_x < 300 + \
		PLAYER_MOVE_SPEED * 1.5 || data->player.pos_y < 300 + \
		PLAYER_MOVE_SPEED * 1.5 || data->player.pos_x > \
		(data->cols - 1) * 300 || data->player.pos_y > (data->rows) * 300)
		{
			data->player.pos_x = data->player.previous_pos_x;
			data->player.pos_y = data->player.previous_pos_y;
		}
	}
	if (data->player.camera_x < 0)
		data->player.camera_x = 360 + data->player.camera_x;
	if (data->player.camera_x >= 360)
		data->player.camera_x = data->player.camera_x - 360;
	move_finish(data);
}
