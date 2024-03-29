/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:33:02 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 10:22:57 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int key, t_data *data)
{
	if (key == ESC)
		on_destroy(data, 1);
	else
		move(data, key);
	if (data->map.coin == 0
		&& data->map.map[data->pos_p.y][data->pos_p.x] == 'E')
		on_destroy(data, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "Error.\n", 7);
		exit (1);
	}
	check_file(argv[1]);
	init_map(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.map.x * 50, data.map.y * 50, "hi :)");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit (1);
	}
	draw_map(&data);
	mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
