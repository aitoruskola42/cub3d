/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:02 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 16:42:40 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* 	
	int	max;

	max = MAX_X_SIZE;
	print_text_on_screen(data, "Brujula: ", max - 150, 25);
	print_text_on_screen(data, ft_itoa(data->player.camera_x), max - 90, 25);
	print_text_on_screen(data, "X: ", max - 150, 45);
	print_text_on_screen(data, ft_itoa(data->player.pos_x), max - 135, 45);
	print_text_on_screen(data, "Y: ", max - 110, 45);
	print_text_on_screen(data, ft_itoa(data->player.pos_y), max - 95, 45); */

void	animate_background(t_data *data)
{
	double	rayangle;
	double	cos_value;
	double	sin_value;

	rayangle = (data->player.camera_x * M_PI / 180);
	sin_value = sin(rayangle);
	cos_value = cos(rayangle);
	make_move(data, cos_value, sin_value);
	copy_image_buffer3d(data, data->cell_img, 0);
	copy_image_buffer3d(data, data->floor_img, 540);
	print_animation_images3d (data, 0, 0);
	debug_cols(data);
	print_image_from_memory(data, data->img_copy_ptr);
}
