/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:32:28 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 13:40:53 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_NAME "so_long"
# include "./minilibx-linux/mlx.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC 0xff1b
# define DINO "./images/perso.xpm"
# define COIN "./images/coin.xpm"
# define EXIT "./images/exit.xpm"
# define WALL "./images/wall1.xpm"
# define GROUND "./images/ground1.xpm"

typedef struct s_map
{
	char	**map;
	void	*img_perso;
	void	*img_wall;
	void	*img_exit;
	void	*img_coin;
	void	*img_ground;
	int		x;
	int		y;
	int		player;
	int		coin;
	int		exit;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_pos	pos_p;
	int		moves;
}	t_data;

/* PUT_IMG*/
void	load_image(t_data *data);
void	draw_image(t_data *data, char obj, int x, int y);
void	draw_map(t_data *data);
void	free_map(char **map);

/*MAP*/
int		count_line(char *file);
char	**get_map(char *file);
void	count_param(t_data *data);
void	init_map(t_data *data, char *file);

/* MAP_AUX*/
void	get_the_line(t_data *data, char *file);
void	get_the_columns(t_data *data, char *file);

/*GAME_MOVE*/
void	get_position(t_data *data);
int		check_move(t_data *data, char c);
void	put_image_move(t_data *data, char c, int x, int y);
void	move(t_data *data, int key);

/*VALIDATION*/
void	check_components(t_data *data);
void	check_param(t_data *data);
void	check_rectangular(t_data *data);
void	check_walls(t_data *data);

/*VALIDATION2*/
void	check_exit_patch(t_data *data, char *file);
void	check_exit_around(t_data *data, char **map);
int		check_around(int x, int y, char **map);
void	fill_map(t_data *data, int y, int x, char **map);

/*VALIDATION3*/
void	check_file(char *file);

/*ERROR*/
void	game_error(t_data *data);
int		on_destroy(t_data *data, int img);
void	putnbr(int n);
#endif