/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:28:33 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/19 11:29:12 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_memory_images(t_data *data)
{
	empty_file("textures/floor.xpm");
	empty_file("textures/cell.xpm");
	data->floor_color.color = rgb_to_hex(data->floor_color.red, \
	data->floor_color.green, data->floor_color.blue);
	data->cell_color.color = rgb_to_hex(data->cell_color.red, \
	data->cell_color.green, data->cell_color.blue);
	write_on_file("/* XPM */\n", "textures/floor.xpm");
	write_on_file("/* XPM */\n", "textures/cell.xpm");
	write_on_file("static char * floor_xpm[] = {\n", "textures/floor.xpm");
	write_on_file("static char * cell[] = {\n", "textures/cell.xpm");
	write_on_file("\"", "textures/floor.xpm");
	write_on_file("\"", "textures/cell.xpm");
	load_memory_images2(data);
	copy_image_buffer_cols(data, data->north_img, data->north_cols);
	copy_image_buffer_cols(data, data->south_img, data->south_cols);
	copy_image_buffer_cols(data, data->west_img, data->west_cols);
	copy_image_buffer_cols(data, data->east_img, data->east_cols);
}

void	load_memory_images2(t_data *data)
{
	char	*size;

	size = ft_itoa(MAX_X_SIZE);
	write_on_file(size, "textures/floor.xpm");
	write_on_file(" ", "textures/floor.xpm");
	write_on_file(size, "textures/cell.xpm");
	write_on_file(" ", "textures/cell.xpm");
	free (size);
	size = ft_itoa(MAX_Y_SIZE / 2);
	write_on_file(size, "textures/floor.xpm");
	write_on_file(size, "textures/cell.xpm");
	free (size);
	write_on_file(" 1 1\",\n", "textures/floor.xpm");
	write_on_file(" 1 1\",\n", "textures/cell.xpm");
	write_on_file("\"  c #", "textures/floor.xpm");
	write_on_file("\"  c #", "textures/cell.xpm");
	write_on_file(rgb_to_hex(data->floor_color.red, \
	data->floor_color.green, data->floor_color.blue), "textures/floor.xpm");
	write_on_file(rgb_to_hex(data->cell_color.red, \
	data->cell_color.green, data->cell_color.blue), "textures/cell.xpm");
	write_on_file("\",\n", "textures/floor.xpm");
	write_on_file("\",\n", "textures/cell.xpm");
	bucle_on_file("textures/floor.xpm");
	bucle_on_file("textures/cell.xpm");
	load_memory_images3(data);
}

void	load_textures_bonus(t_data *data)
{
	data->cell_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"textures/cell.xpm", &data->res, &data->res);
	if (!data->cell_img)
		map_error(data, "wrong img", 1);
	data->cell_img->rows = data->window_height / 2;
	data->cell_img->cols = data->window_width;
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"textures/floor.xpm", &data->res, &data->res);
	if (!data->floor_img)
		map_error(data, "wrong img", 1);
	data->floor_img->rows = data->window_height / 2;
	data->floor_img->cols = data->window_width;
}

void	load_memory_images3(t_data *data)
{
	write_on_file("};", "textures/floor.xpm");
	write_on_file("};", "textures/cell.xpm");
	load_textures_bonus(data);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"textures/player.xpm", &data->res, &data->res);
	if (!data->player_img)
		map_error(data, "wrong img", 1);
	data->player_img->rows = WIDTH_3D_IMAGE;
	data->player_img->cols = WIDTH_3D_IMAGE;
	data->player.pos_x = -1;
	data->player.pos_y = -1;
	load_memory_images4(data);
}

void	load_memory_images4(t_data *data)
{
	data->north_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->north_pic, &data->res, &data->res);
	if (!data->north_img)
		map_error(data, "wrong img", 1);
	data->north_img->rows = WIDTH_3D_IMAGE;
	data->north_img->cols = WIDTH_3D_IMAGE;
	data->south_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->south_pic, &data->res, &data->res);
	if (!data->south_img)
		map_error(data, "wrong img", 1);
	data->south_img->rows = WIDTH_3D_IMAGE;
	data->south_img->cols = WIDTH_3D_IMAGE;
	data->west_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->west_pic, &data->res, &data->res);
	if (!data->west_img)
		map_error(data, "wrong img", 1);
	data->west_img->rows = WIDTH_3D_IMAGE;
	data->west_img->cols = WIDTH_3D_IMAGE;
	data->east_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->east_pic, &data->res, &data->res);
	if (!data->east_img)
		map_error(data, "wrong img", 1);
	data->east_img->rows = WIDTH_3D_IMAGE;
	data->east_img->cols = WIDTH_3D_IMAGE;
}
