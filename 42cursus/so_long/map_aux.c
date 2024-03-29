/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:33:50 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:20:40 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_the_line(t_data *data, char *file)
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
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.y = i;
	close(fd);
}

void	get_the_columns(t_data *data, char *file)
{
	int		fd;
	int		columns;
	char	*line;

	columns = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line[columns] != '\n')
		columns++;
	free(line);
	close(fd);
	data->map.x = columns;
}
