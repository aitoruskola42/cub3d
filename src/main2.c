/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:19:50 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 12:35:31 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_argc(t_data *data, int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc == 1)
		map_error(data, "Please insert .cub file map path. \n\
./cub3d \"maps/mapa.cub\"\n", 1);
	if (argc > 2)
		map_error(data, "Too many argumensts.", 1);
	if (argc == 2)
	{
		data->argv_map = argv[1];
		i = ft_strlen(data->argv_map);
		if (data->argv_map[i - 4] == '.' && data->argv_map[i - 3] == 'c' \
		&& data->argv_map[i - 2] == 'u' && data->argv_map[i - 1] == 'b')
		{
			fd = open(data->argv_map, O_RDONLY);
			if (fd < 0)
				map_error(data, "Cant open map file", 1);
			close (fd);
		}
		else
			map_error(data, "Map file extension must be \".cub\".", 1);
	}
	return (0);
}

void	empty_file(const char *file_name)
{
	int	this_file;

	this_file = open(file_name, O_TRUNC | O_CREAT, 0644);
	if (this_file == -1)
		exit(1);
	close(this_file);
}

void	write_on_file(char *str, const char *file_name)
{
	int	this_file;

	this_file = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (this_file == -1)
		exit(1);
	write(this_file, str, strlen(str));
	close(this_file);
}

void	bucle_on_file2(int this_file, char *size)
{
	write(this_file, size, MAX_X_SIZE);
	write(this_file, "\",\n", 3);
}

void	bucle_on_file( const char *file_name)
{
	int		this_file;
	int		y;
	int		x;
	char	*size;

	x = 0;
	this_file = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (this_file == -1)
		map_error(NULL, "Error opening file", 1);
	while (x < (MAX_Y_SIZE / 2))
	{
		y = 0;
		write(this_file, "\"", 1);
		size = malloc(MAX_X_SIZE + 2);
		while (y < MAX_X_SIZE)
		{
			size[y] = ' ';
			y++;
		}
		size[y] = '\0';
		bucle_on_file2(this_file, size);
		free (size);
		x++;
	}
	close(this_file);
}
