/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:08 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:20:16 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error\n");
		exit(1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**get_map(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = count_line(file);
	map = malloc(sizeof(char *) * i);
	if (!map)
		exit (1);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		free_map(map);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	map[i] = '\0';
	return (map);
}

void	count_param(t_data *data)
{
	int	i;
	int	j;

	data->map.player = 0;
	data->map.coin = 0;
	data->map.exit = 0;
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
				data->map.player += 1;
			else if (data->map.map[i][j] == 'E')
				data->map.exit += 1;
			else if (data->map.map[i][j] == 'C')
				data->map.coin += 1;
			j++;
		}
		i++;
	}
}

void	init_map(t_data *data, char *file)
{
	data->moves = 0;
	get_the_line(data, file);
	get_the_columns(data, file);
	data->map.map = get_map(file);
	get_position(data);
	count_param(data);
	check_rectangular(data);
	check_components(data);
	check_param(data);
	check_walls(data);
	check_exit_patch(data, file);
}
