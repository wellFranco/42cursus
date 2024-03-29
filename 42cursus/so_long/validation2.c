/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:31:54 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:05:00 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_data *data, int y, int x, char **map)
{
	if (x < 0 || y < 0 || x > data->map.x || y > data->map.y)
		return ;
	if (map[y][x] == 'P' || map[y][x] == '1'
	|| map[y][x] == 'E' || map[y][x] == '\0')
		return ;
	map[y][x] = 'P';
	fill_map(data, y + 1, x, map);
	fill_map(data, y - 1, x, map);
	fill_map(data, y, x + 1, map);
	fill_map(data, y, x - 1, map);
}

int	check_around(int x, int y, char **map)
{
	if (map[y + 1][x] == 'P' || map[y - 1][x] == 'P'
	|| map[y][x + 1] == 'P' || map[y][x - 1] == 'P')
		return (0);
	return (1);
}

void	check_exit_around(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || data->map.map[i][j] == 'C')
			{
				if (check_around(j, i, map))
				{
					free_map(map);
					game_error(data);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_exit_patch(t_data *data, char *file)
{
	int		x;
	int		y;
	char	**map;

	y = data->pos_p.y;
	x = data->pos_p.x;
	map = get_map(file);
	fill_map(data, y + 1, x, map);
	fill_map(data, y - 1, x, map);
	fill_map(data, y, x + 1, map);
	fill_map(data, y, x - 1, map);
	fill_map(data, y, x, map);
	check_exit_around(data, map);
	free_map(map);
}
