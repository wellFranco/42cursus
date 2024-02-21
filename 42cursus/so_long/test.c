#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct {

    void    *mlx;
    void    *mlx_win;

} ptr;

int key_mov(int keymov, void *tmp)
{
    ptr *vars = (ptr *)tmp;
    int width;
    int height;
    void    *img;
    printf("%c\n", keymov);
    if(keymov == 'w' || keymov == 'a'|| keymov == 's' || keymov == 'd')
    {
        img = mlx_xpm_file_to_image(vars->mlx, "./Dino.xpm", &width, &height);
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, 0, 0);
    }
}


int	main(void)
{
	ptr new;

	new.mlx = mlx_init();
	new.mlx_win = mlx_new_window(new.mlx, 500, 200, "Hello world!");
    mlx_key_hook(new.mlx_win, key_mov, &new);
	mlx_loop(new.mlx);
}