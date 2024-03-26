/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:39 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/26 18:14:01 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longe.h"

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
			if(data->map.map != '0' && data->map.map[i][j] != '1'
			&& data->map.map[i][j] != 'C' && data->map.map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
}

void	check_param(t_data *data)
{
	if (data->map.player != 1 || data->map.coin < 1 || data->map.exit != 1)
		write(1,"Error\n", 6);
}