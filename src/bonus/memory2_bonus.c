/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:59 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/19 09:59:17 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	exit_click(t_data *data)
{
	data->i = 0;
	exit(0);
}

int	free_malloc1(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->rows)
	{
		if (d->check_map[i] != NULL)
			free(d->check_map[i]);
		if (d->map[i] != NULL)
			free(d->map[i]);
		i++;
	}
	free(d->check_map);
	free(d->map);
	i = 0;
	return (0);
}

void	make_malloc(t_data *d)
{
	d->made_malloc = 1;
	d->i = 0;
	d->check_map = (char **)malloc (d->rows * WIDTH_3D_IMAGE * sizeof(char *));
	if (d->check_map == NULL)
		map_error(d, "Error: Malloc error for rows of check_map.\n", 1);
	while (d->i < d->rows * WIDTH_3D_IMAGE)
	{
		d->check_map[d->i] = (char *)malloc(d->cols * \
		WIDTH_3D_IMAGE * sizeof(char));
		if (d->check_map[d->i] == NULL)
			map_error(d, "Error: Malloc error for cols of check_map.\n", 1);
		d->i++;
	}
	make_malloc2(d);
}

void	make_malloc2(t_data *d)
{
	int	i;

	i = 0;
	d->map = (char **)malloc(d->rows * WIDTH_3D_IMAGE * sizeof(char *));
	if (d->map == NULL)
		map_error(d, "Error: can not reserve memory for rows.\n", 1);
	while (i < d->rows * WIDTH_3D_IMAGE)
	{
		d->map[i] = (char *)malloc(d->cols * WIDTH_3D_IMAGE * sizeof(char));
		if (d->map[i] == NULL)
			map_error(d, "Error: can not reserve memory for cols.\n", 1);
		i++;
	}
}
