#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 500
# define WIN_H 500
# define IMG_W 50
# define IMG_H 50
# define WIN_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COIN 'C'


#include "./minilibx-linux/mlx.h"
#include "./libft/get_next_line.h"
#include "./libft/libft.h"
//#include <x11/keysym.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

# define ESC 0xff1b

typedef struct s_map
{
	char **map;
	size_t	w_map;
    size_t	h_map;
	int	x;
	int	y;
	int	fd;
}   t_map;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_map   map;
	// t_img	img;
    void    *win_img;
}   t_data;


void	draw_background(t_data *data, char *image_path, int width, int height);

#endif