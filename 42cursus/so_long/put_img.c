/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:33:17 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 09:45:09 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_data *data)
{
	data->map.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			WALL, &data->map.x, &data->map.y);
	data->map.img_ground = mlx_xpm_file_to_image(data->mlx_ptr,
			GROUND, &data->map.x, &data->map.y);
	data->map.img_perso = mlx_xpm_file_to_image(data->mlx_ptr,
			DINO, &data->map.x, &data->map.y);
	data->map.img_coin = mlx_xpm_file_to_image(data->mlx_ptr,
			COIN, &data->map.x, &data->map.y);
	data->map.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			EXIT, &data->map.x, &data->map.y);
}

void	draw_image(t_data *data, char obj, int x, int y)
{
	if (obj == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map.img_wall, x * 50, y * 50);
	else if (obj == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map.img_ground, x * 50, y * 50);
	else if (obj == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map.img_coin, x * 50, y * 50);
	else if (obj == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map.img_perso, x * 50, y * 50);
	else if (obj == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map.img_exit, x * 50, y * 50);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	load_image(data);
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			draw_image(data, data->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}
