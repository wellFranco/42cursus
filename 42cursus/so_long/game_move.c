/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:27:28 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/26 17:32:41 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_data *data)
{
    int	i;
	int	j;

	i = 0;
	while(data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if(data->map.map[i][j] == 'P')
			{
				data->pos_p.y = i;
				data->pos_p.x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	make_move(t_data *data, int key)
{
	if(key == 'w')
	{
		
	}
	else if(key == 'a')
	{
		
	}
	else if(key == 's')
	{
		
	}
	else if(key == 'd')
	{
		
	}
}

