/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:34:06 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:03:21 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	game_error(t_data *data)
{
	write(1, "Error.\n", 7);
	write(1, "mapa irregular.\n", 16);
	if (data->map.map)
		free_map(data->map.map);
	exit(1);
}

int	on_destroy(t_data *data, int img)
{
	free_map(data->map.map);
	if (img)
	{
		mlx_destroy_image(data->mlx_ptr, data->map.img_ground);
		mlx_destroy_image(data->mlx_ptr, data->map.img_perso);
		mlx_destroy_image(data->mlx_ptr, data->map.img_coin);
		mlx_destroy_image(data->mlx_ptr, data->map.img_exit);
		mlx_destroy_image(data->mlx_ptr, data->map.img_wall);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	putnbr(int n)
{
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}
