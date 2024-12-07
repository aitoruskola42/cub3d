/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:58:25 by incalero          #+#    #+#             */
/*   Updated: 2024/06/17 09:58:26 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	ft_check_cadena(t_data *data, char *cadena)
{
	int	i;
	int	cont;

	(void)data;
	i = 0;
	cont = 0;
	while (cadena[i])
	{
		if (cadena[i] == ',')
			cont++;
		if (cadena[i] != ',' && cadena[i] != ' ' && \
		(cadena[i] < '0' || cadena[i] > '9'))
			map_error(data, "Grong color number, \
			RGB = (0/255, 0/255, 0/255)\n", 1);
		i++;
	}
	if (cont > 2)
		map_error(data, "Grong color number, RGB = (0/255, 0/255, 0/255)\n", 1);
}

void	check_color(t_data *data, char **token)
{
	int	i;

	(void)data;
	i = 0;
	while (token[i])
		i++;
	if (i > 3)
		map_error(data, "Grong color number, RGB", 1);
	i = 0;
	while (i < 3)
	{
		if (token[i] == NULL || atoi(token[i]) < 0 || atoi(token[i]) > 255)
		{
			map_error(data, "Grong color number, \
			RGB = (0/255, 0/255, 0/255)\n", 1);
			exit(0);
		}
		i++;
	}
}

void	obtener_colores(t_data *data, char *cadena, char where)
{
	char	**token;

	token = ft_split(cadena, ',');
	ft_check_cadena(data, cadena);
	check_color(data, token);
	if (where == 'F')
	{
		data->floor_color.red = atoi(token[0]);
		data->floor_color.green = atoi(token[1]);
		data->floor_color.blue = atoi(token[2]);
	}
	else
	{
		data->cell_color.red = atoi(token[0]);
		data->cell_color.green = atoi(token[1]);
		data->cell_color.blue = atoi(token[2]);
	}
	free (cadena);
}
