/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:39 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 09:50:08 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_components(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] != '0' && data->map.map[i][j] != '1'
			&& data->map.map[i][j] != 'C' && data->map.map[i][j] != 'P'
			&& data->map.map[i][j] != 'E')
			{
				game_error(data);
			}
			j++;
		}
		i++;
	}
}

void	check_param(t_data *data)
{
	if (data->map.player != 1 || data->map.exit != 1)
		game_error(data);
	if (data->map.coin < 1)
		game_error(data);
}

void	check_rectangular(t_data *data)
{
	if ((data->map.y == data->map.x)
		|| data->map.x <= 2 || data->map.y <= 2)
		game_error(data);
}

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.y)
	{
		if (data->map.map[i][0] != '1'
		|| data->map.map[i][data->map.x - 1] != '1')
		{
			game_error(data);
		}
		i++;
	}
	i = 0;
	while (i < data->map.x)
	{
		if (data->map.map[0][i] != '1'
		|| data->map.map[data->map.y - 1][i] != '1')
		{
			game_error(data);
		}
		i++;
	}
}
