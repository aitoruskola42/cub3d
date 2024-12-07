/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:56:14 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/19 12:11:31 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_char(t_data *data, char key)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	j = 0;
	counter = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] == key)
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	return (counter);
}

int	check_map(t_data *data, char *text)
{
	int	line_size;

	if (text[ft_strlen(text) - 1] == '\n')
		text[ft_strlen(text) - 1] = '\0';
	line_size = ft_strlen(text);
	data->rows = data->rows + 1;
	if (data->cols != 0)
		if (data->cols != line_size)
			map_error(data, "Incorrect rows/cols", 1);
	if (data->cols > MAX_COLS)
		map_error(data, "Too big number of COLS", 1);
	if (data->rows > MAX_ROWS)
		map_error(data, "Too big number of rows", 1);
	return (1);
}

void	wrong_img(t_data *data, char *img_card)
{
	int		fd;

	(void) data;
	fd = open(img_card, O_RDONLY);
	if (fd < 0)
		map_error(data, "wrong img", 1);
}

void	check_map_line_2(t_data *data, char *trimed, char *err_mess)
{
	if (strncmp(trimed, "NO", 2) == 0)
	{
		if (data->north == 1)
			map_error(data, err_mess, 1);
		data->north = 1;
		data->north_pic = ft_substr(trimed, 3, ft_strlen(trimed) - 3);
		data->north_pic = ltrim(data->north_pic);
		wrong_img(data, data->north_pic);
	}
	if (strncmp(trimed, "SO", 2) == 0)
	{
		if (data->south == 1)
			map_error(data, err_mess, 1);
		data->south = 1;
		data->south_pic = ft_substr(trimed, 3, ft_strlen(trimed) - 3);
		data->south_pic = ltrim(data->south_pic);
		wrong_img(data, data->south_pic);
	}
}

void	check_map_line_3(t_data *data, char *trimed, char *err_mess)
{
	if (strncmp(trimed, "EA", 2) == 0)
	{
		if (data->east == 1)
			map_error(data, err_mess, 1);
		data->east = 1;
		data->east_pic = ft_substr(trimed, 3, ft_strlen(trimed) - 3);
		data->east_pic = ltrim(data->east_pic);
		wrong_img(data, data->east_pic);
	}
}
