/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:54 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/19 12:12:03 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

//int	posicion;
//posicion = 0;
/* while (posicion < (int)ft_strlen(trimed))
{
	
	if (trimed[posicion] == '*')
		map_error (data, "Invalid map line detected");
	posicion ++;
} */

void	check_map_line_4(t_data *data, char *trimed)
{
	if (data->started_map_values == 0)
		data->started_map_values = 1;
	if (ft_strlen(trimed) == 0)
		map_error(data, "Invalid map line detected1.", 1);
	if (data->started_map_values == 1 && trimed[0] != '1' \
	&& trimed[0] != '*' && trimed[0] != ' ')
		map_error(data, "Invalid map line detected2.", 1);
}

int	check_map_line(t_data *data, char *text, int row)
{
	char	*trimed;

	trimed = ft_strtrim(text, " ");
	if (strncmp(trimed, "NO", 2) == 0 && data->started_map_values == 0)
		check_map_line_2(data, trimed, "Duplicate NO");
	else if (strncmp(trimed, "SO", 2) == 0 && data->started_map_values == 0)
		check_map_line_2(data, trimed, "Duplicate SO");
	else if (strncmp(trimed, "WE", 2) == 0 && data->started_map_values == 0)
		check_map_line_6(data, trimed, "Duplicate WE");
	else if (strncmp(trimed, "EA", 2) == 0 && data->started_map_values == 0)
		check_map_line_3(data, trimed, "Duplicate EA");
	else if (strncmp(trimed, "F", 1) == 0 && data->started_map_values == 0)
		obtener_colores(data, ft_substr(trimed, 2, ft_strlen(trimed) - 2), 'F');
	else if (strncmp(trimed, "C", 1) == 0 && data->started_map_values == 0)
		obtener_colores(data, ft_substr(trimed, 2, ft_strlen(trimed) - 2), 'C');
	else if (strncmp(trimed, "\0", 1) == 0 && data->started_map_values == 0)
		return (free(trimed), 1);
	else
	{
		check_map_line_4(data, trimed);
		check_map_line2(data, text, row);
	}
	free (trimed);
	return (1);
}

int	check_map_line2(t_data *data, char *text, int row)
{
	int	i;

	data->started_map_values = 1;
	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] != '1' && text[i] != '0' \
		&& text[i] != 'N' && text[i] != 'S' && text[i] != 'E' \
		&& text[i] != 'W' && text[i] != ' ' && text[i] != '*' && text[i] != '-')
			map_error(data, "Invalid map line detected", 1);
		if (text[i] == ' ')
			text[i] = '*';
		data->map[row][i] = text[i];
		i++;
	}
	while (i < data->cols)
	{
		data->map[row][i] = '*';
		i++;
	}
	return (1);
}

int	check_mark(t_data *data, int x, int y)
{
	int	changed;

	changed = 0;
	if (data->check_map[x][y] == '1' || data->check_map[x][y] == '-')
		return (0);
	if (x < data->rows -1 && x > 0)
	{
		if (data->check_map[x + 1][y] == '-' \
		|| data->check_map[x - 1][y] == '-')
			changed = 1;
	}
	if (y < data->cols -1 && y > 0)
	{
		if (data->check_map[x][y -1] == '-' || data->check_map[x][y + 1] == '-')
			changed = 1;
	}
	if (changed == 1)
	{
		if (data->check_map[x][y] == '0')
			data->check_map[x][y] = '-';
		if (data->check_map[x][y] == '*')
			map_error(data, "Found a open space, no closed map", 1);
	}
	return (changed);
}

void	check_map_line_6(t_data *data, char *trimed, char *err_mess)
{
	if (strncmp(trimed, "WE", 2) == 0)
	{
		if (data->west == 1)
			map_error(data, err_mess, 1);
		data->west = 1;
		data->west_pic = ft_substr(trimed, 3, ft_strlen(trimed) - 3);
		data->west_pic = ltrim(data->west_pic);
		wrong_img(data, data->west_pic);
	}
}
