/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:52:03 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 15:44:54 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	check_map_finished(t_data *new_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < new_map->rows)
	{
		while (j < new_map->cols)
		{
			if (new_map->map[i][j] == '*')
			{
				check_map_error(new_map, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_valid_road(t_data *data)
{
	int		changed;
	int		i;
	int		j;

	j = 0;
	changed = 1;
	while (changed-- == 1)
	{
		i = 0;
		while (i < data->rows)
		{
			while (j < data->cols)
			{
				if (check_mark(data, i, j))
					changed = 1;
				j++;
			}
			j = 0;
			i++;
		}
	}
	if (check_map_finished(data))
		return (1);
	return (0);
}

void	check_valid_road2(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
			|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
				data->check_map[i][j] = '-';
			else
				data->check_map[i][j] = data->map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_map_error(t_data *new_map, int i, int j)
{
	if (i > 0)
	{
		if (new_map->map[i - 1][j] == '0')
			map_error(new_map, "Map error", 1);
	}
	if (i < new_map->rows - 1)
	{
		if (new_map->map[i + 1][j] == '0')
			map_error(new_map, "Map error", 1);
	}
	if (j > 0)
	{
		if (new_map->map[i][j - 1] == '0')
			map_error(new_map, "Map error", 1);
	}
	if (j < new_map->cols - 1)
	{
		if (new_map->map[i][j + 1] == '0')
			map_error(new_map, "Map error", 1);
	}
}
