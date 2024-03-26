#include "so_long.h"

void	load_image(t_data *data)
{
	//void	*img_ptr;
	int		img_width;
	int		img_height;

	data->map.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
	WALL, &img_width, &img_height);
	data->map.img_perso = mlx_xpm_file_to_image(data->mlx_ptr,
	DINO, &img_width, &img_height);
	data->map.img_coin = mlx_xpm_file_to_image(data->mlx_ptr,
	COIN, &img_width, &img_height);
	data->map.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
	EXIT, &img_width, &img_height);

	//img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
	//		image_path, &img_width, &img_height);
	//return (img);data->map.x++;
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, width, height);
	//free(img_ptr);
}

void	draw_image(t_data *data, char obj, int x, int y)
{
	if (obj == '1')
		mlx_put_image_to_window(data->mlx_ptr,
	data->win_ptr, data->map.img_wall, x, y);
	else if (obj == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
	data->win_ptr, data->map.img_coin, x, y);
	else if (obj == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
	data->win_ptr, data->map.img_perso, x, y);
	else if (obj == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
	data->win_ptr, data->map.img_exit, x, y);
}

void	draw_map(t_data *data)
{
	int i;
	int	j;

	i = 0;
	load_image(data);
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			draw_image(data, data->map.map[i][j], j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}


int	destroy_window(t_data *data, int img)
{
	free_map(data->map.map);
	if(img)
	{
		mlx_destroy_image(data->win_ptr, data->win_img);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}