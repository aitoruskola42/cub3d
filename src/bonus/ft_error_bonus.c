/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:40:19 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/19 11:27:43 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

/* 	free_malloc1(data);
	free_malloc2(data); */

void	map_error( t_data *data, char *description, int reason)
{
	(void)data;
	if (reason > 0)
	{
		write(1, "Error\n", 6);
		write(1, description, ft_strlen(description));
	}
	if (data->made_malloc == 1)
	{
		free_malloc1(data);
	}
	exit (reason);
}
