/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:07:25 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 12:09:06 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*rgb_to_hex(unsigned int r, unsigned int g, unsigned int b)
{
	static char	hex_string[7];
	char		*hex_chars;

	hex_chars = ft_strdup("0123456789ABCDEF");
	hex_string[1] = hex_chars[r % 16];
	hex_string[0] = hex_chars[r / 16];
	hex_string[3] = hex_chars[g % 16];
	hex_string[2] = hex_chars[g / 16];
	hex_string[5] = hex_chars[b % 16];
	hex_string[4] = hex_chars[b / 16];
	hex_string[6] = '\0';
	free (hex_chars);
	return (hex_string);
}

int	check_map_chars(t_data *data)
{
	int	sum;

	sum = (data->rows + 1) * (data->cols);
	sum = sum - check_map_char(data, 'F', "Floor color error");
	sum = sum - check_map_char(data, 'C', "Cell color error");
	sum = sum - check_map_char(data, 'N', "Player north pos error");
	sum = sum - check_map_char(data, 'S', "Player south pos error");
	sum = sum - check_map_char(data, 'W', "Player west pos error");
	sum = sum - check_map_char(data, 'E', "Player east pos error");
	sum = sum - check_map_char(data, '0', "No Free spaces on map");
	sum = sum - check_map_char(data, '1', "No Walls in the map");
	if (sum != 0)
		map_error(data, "Error on mapa chars", 1);
	return (0);
}
