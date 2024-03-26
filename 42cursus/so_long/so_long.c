//#include "./minilibx-linux/mlx.h"
//#include "./libft/get_next_line.h"
//#include "./libft/libft.h"
//#include <x11/keysym.h>
#include "so_long.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>





// typedef struct s_img
// {
// 	void	*wall;
// 	void	*play;
// 	void	*coin;
// 	void	*exit;

// }	t_img;



//UTILs



int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	// int width;
	// int height;
	printf("%c\n", keysym);
	if(keysym == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return(0);
	
}


int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		write(1, "Error", 5);
		exit (1);
	}
		
data.mlx_ptr = mlx_init();
init_map(&data, argv[1]);
data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.x * 50 , data.map.y * 50, "hi :)");
// data.win_ptr = mlx_new_window(data.mlx_ptr, 100, 100, "cavalo");
printf("y: %d\tx: %d\n", data.map.y, data.map.x);
// data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.y * 50, data.map.x * 50, "hi :)");
draw_map(&data);
	//printf("%d\n%d\n", data.map.x, data.map.y);

	
	//if (!data.mlx_ptr)
	//	return (1);
	
	//if (!data.win_ptr)
		//return (free(data.mlx_ptr), 1);	
	mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}