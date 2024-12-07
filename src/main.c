/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:02 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 14:49:53 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		map_error(data, "Win_ptr NULL", 1);
	animate_background(data);
	return (0);
}

int	check_map_char(t_data *data, char key, char *error_message)
{
	int	counter;

	counter = check_char(data, key);
	if (counter != 1)
		map_error(data, error_message, 1);
	return (counter);
}

void	load_height_and_width2(t_data *data, char	*text )
{
	char	*trimed;

	if (text[ft_strlen(text) - 1] == '\n')
		text[ft_strlen(text) - 1] = '\0';
	trimed = ft_strtrim(text, " ");
	if (trimed[0] == '1')
		data->started_map_values = 1;
	if (data->started_map_values == 1)
	{
		data->rows++;
		if ((int)ft_strlen(text) > data->cols)
			data->cols = ft_strlen(text);
		if (ft_strlen(trimed) > 0)
		{
			if (trimed[0] != '1' && trimed[0] != ' ' && trimed[0] != '0')
			{
				map_error(data, "Error in line", 1);
			}
		}
	}
	free (trimed);
}

void	load_height_and_width(t_data *data)
{
	int		fd;
	char	*text;

	fd = open(data->argv_map, O_RDONLY);
	if (fd < 0)
		return ;
	text = get_next_line(fd);
	while (text != NULL)
	{
		if (text == NULL)
			return ;
		load_height_and_width2(data, text);
		free(text);
		text = get_next_line(fd);
	}
	free(text);
	close(fd);
	data->started_map_values = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;

	load_initial_data(&data);
	load_initial_data2(&data);
	check_argc(&data, argc, argv);
	load_height_and_width(&data);
	make_malloc(&data);
	fd = open(data.argv_map, O_RDONLY);
	if (fd < 0)
		map_error(&data, "Error opening file", 1);
	load_file(&data, 0, fd);
	check_map_player(&data, 0);
	debug_map_definitions(&data);
	check_valid_road(&data);
	load_mlx(&data);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.img.mlx_img);
	return (0);
}
