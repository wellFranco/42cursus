//#include "./minilibx-linux/mlx.h"
//#include "./libft/get_next_line.h"
//#include "./libft/libft.h"
//#include <x11/keysym.h>
#include "so_long.h"
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
    void    *img;
}   t_data;

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
    int width;
    int height;
	printf("%c\n", keysym);
    if(keysym == 'w')
    {
        data->img = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Dino.xpm", &width, &height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    }
	if(keysym == 0xff1b)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return(0);
	
}

//MAP                              //
int	count_line()
{
	int fd;
	//char *line;
	int	line;

	line = 0;
	fd = open("./map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("deu ruim");
		exit(1);
	}
	while(get_next_line(fd))
	{
		line++;
	}
	//printf("%d\n", line);
	close(fd);
	return (line);
}

int	count_columns()
{
	int fd;
	int	columns;

	columns = 0;
	fd =open("./map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("deu ruim");
		exit(1);
	}
	columns = ft_strlen(get_next_line(fd)) - 1;
	//printf("%d\n", columns);
	close(fd);
	return (columns);
}

//MAP                            //

int main(void)
{
	t_data data;
	data.map.x = count_line();
	data.map.y = count_columns();


	int i;

	data.map.map = malloc((data.map.x + 1) * sizeof(char *));
	i = 0;
	while(i <= data.map.x)
	{
		data.map.map[i] = malloc((data.map.y + 1) * sizeof(char));
		data.map.map[i][data.map.y] = '\0';
		i++;
	}
	i = 0;
	while (i <= data.map.y)
	{
		data.map.map[data.map.x][i] = '\0';
		i++;
	}


i = 0;
int j = 0;
while (j < data.map.y)
{
	i = 0;
	while (i < data.map.x)
	{
		data.map.map[i][j] = 'X';
		i++;
	}
	j++;
}

i = 0;
j = 0;
while (data.map.map[i][0])
{
	j = 0;
	while (data.map.map[0][j])
	{
		write(1, &data.map.map[i][j], 1);
		j++;
	}
	write(1, "\n", 1);
	i++;
}




	//printf("%d\n%d\n", data.map.x, data.map.y);

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