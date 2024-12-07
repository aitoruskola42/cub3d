/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:58:14 by incalero          #+#    #+#             */
/*   Updated: 2024/06/19 10:04:20 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	handle_mouse(int keysym, t_data *data)
{
	(void)data;
	(void)keysym;
	return (1);
}

void	load_initial_data(t_data *data)
{
	data->debug_mode = 0;
	data->res = WIDTH_3D_IMAGE;
	data->rows = 0;
	data->cols = 0;
	data->north_pic = "";
	data->south_pic = "";
	data->east_pic = "";
	data->west_pic = "";
	data->floor_color.red = -1;
	data->floor_color.green = -1;
	data->floor_color.blue = -1;
	data->cell_color.red = -1;
	data->cell_color.green = -1;
	data->cell_color.blue = -1;
	data->made_malloc = 0;
}

void	load_initial_data2(t_data *data)
{
	data->previous_col = -1;
	data->previous_row = -1;
	data->player.time = 0;
	data->player.old_time = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
	data->player.square_x = 0;
	data->player.square_y = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.square_x = 0;
	data->player.square_y = 0;
	data->north = 0;
	data->south = 0;
	data->west = 0;
	data->east = 0;
	data->colision_check = PLAYER_MOVE_SPEED * COLISION_DETECTOR;
}

int	load_file(t_data *data, int row, int fd)
{
	char	*text;
	char	*trimed;

	text = get_next_line(fd);
	trimed = ft_strtrim(text, " ");
	while (text != NULL)
	{
		if (text == NULL)
			return (0);
		if (text[ft_strlen(text) - 1] == '\n')
			text[ft_strlen(text) - 1] = '\0';
		check_map_line(data, text, 0);
		if (data->started_map_values == 1)
		{
			row++;
			check_map_line(data, text, row);
			if (trimed[0] != '1' && trimed[0] != '*')
				break ;
		}
		free(text);
		free(trimed);
		text = get_next_line(fd);
		trimed = ft_strtrim(text, " ");
	}
	return (free(trimed), free(text), close(fd), 0);
}

void	load_mlx(t_data *data)
{
	data->window_width = MAX_X_SIZE;
	data->window_height = MAX_Y_SIZE;
	data->game_title = GAME_NAME;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		map_error (data, "Mlx Ptr NULL\n", 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	MAX_X_SIZE, MAX_Y_SIZE, data->game_title);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		map_error (data, "winptr NULL\n", 1);
	}
	data->img_copy_ptr = mlx_new_image(data->mlx_ptr, \
	MAX_X_SIZE, MAX_Y_SIZE);
	if (data->img_copy_ptr == NULL)
		map_error (data, "ref_image", 1);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, (1L << 0), handle_keypress, data);
	mlx_hook(data->win_ptr, 3, (1L << 1), ft_key_hook_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_click, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_mouse_hook(data->win_ptr, &handle_mouse, data);
	load_memory_images(data);
	mlx_loop(data->mlx_ptr);
}
