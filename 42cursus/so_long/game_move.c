/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:27:28 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:18:42 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->pos_p.y = i;
				data->pos_p.x = j;
			}
			if (data->map.map[i][j] == '\n')
				data->map.map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

int	check_move(t_data *data, char c)
{
	if (c == '1' || (c == 'E' && data->map.coin != 0))
		return (0);
	return (1);
}

void	put_image_move(t_data *data, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.img_perso, x * 50, y * 50);
	if (data->map.map[y][x] == 'C')
	{
		data->map.coin--;
		data->map.map[y][x] = '0';
	}
	data->moves++;
	putnbr(data->moves);
	write(1, "\n", 1);
}

void	move(t_data *data, int key)
{
	if (key == 'w'
		&& check_move(data, data->map.map[data->pos_p.y - 1][data->pos_p.x]))
	{
		draw_image(data, '0', data->pos_p.x, data->pos_p.y);
		put_image_move(data, 'P', data->pos_p.x, --data->pos_p.y);
	}
	else if (key == 's'
		&& check_move(data, data->map.map[data->pos_p.y + 1][data->pos_p.x]))
	{
		draw_image(data, '0', data->pos_p.x, data->pos_p.y);
		put_image_move(data, 'P', data->pos_p.x, ++data->pos_p.y);
	}
	else if (key == 'a'
		&& check_move(data, data->map.map[data->pos_p.y][data->pos_p.x - 1]))
	{
		draw_image(data, '0', data->pos_p.x, data->pos_p.y);
		put_image_move(data, 'P', --data->pos_p.x, data->pos_p.y);
	}
	else if (key == 'd'
		&& check_move(data, data->map.map[data->pos_p.y][data->pos_p.x + 1]))
	{
		draw_image(data, '0', data->pos_p.x, data->pos_p.y);
		put_image_move(data, 'P', ++data->pos_p.x, data->pos_p.y);
	}
}
