#include "./minilibx-linux/mlx.h"
//#include <x11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

# define ESC 0xff1b

typedef struct s_map
{
    int w_map;
    int h_map;
}   t_map;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_map   *map;
    void    *img;
}   t_data;

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
    int width;
    int height;
	printf("Pressed key: %c\\n", keysym);
    if(keysym == 'w')
    {
        data->img = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Dino.xpm", &width, &height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    }
	if(keysym == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return(0);
	
}
 
int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	//if (!data.mlx_ptr)
	//	return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	//if (!data.win_ptr)
		//return (free(data.mlx_ptr), 1);	
    mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}