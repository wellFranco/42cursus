#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 500
# define WIN_H 500
# define IMG_W 50
# define IMG_H 50
# define WIN_NAME "so_long"


#include "./minilibx-linux/mlx.h"
#include "./libft/get_next_line.h"
#include "./libft/libft.h"
//#include <x11/keysym.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

# define ESC 0xff1b
# define DINO "./images/dino.xpm"
# define COIN "./images/coin.xpm"
# define EXIT "./images/exit.xpm"
# define WALL "./images/wall5.xpm"

typedef struct s_map
{
	char	**map;
	char	**copy;
	void	*img_perso;
	void	*img_wall;
	void	*img_exit;
	void	*img_coin;
	int	x;
	int	y;
	int	fd;
	int	player;
	int	coin;
	int	exit;
}   t_map;

typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_map   map;
	t_pos	pos_p;
	t_pos	pos_e;
	// t_img	img;
    void    *win_img;
	int	moves;
}   t_data;

/* PUT_IMG*/
void	load_image(t_data *data);
void	draw_image(t_data *data, char obj, int x, int y);
void	draw_map(t_data *data);
void	free_map(char **map);
int	destroy_window(t_data *data, int img);

/*MAP*/
int	count_line(char *file);
char	**get_map(char *file);
void    count_param(t_data *data);
void    init_map(t_data *data, char *file);

/* MAP_AUX*/
void	get_the_line(t_data *data, char *file);
void	get_the_columns(t_data *data, char *file);

/*GAME_MOVE*/
void	get_position(t_data *data);

/*VALIDATION*/
void	check_components(t_data *data);

#endif