#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_ptr
{
    void	*mlx;
    void	*mlx_win;
	int	map;
	int	xpm;
	int	a;
	int	b;
	int	c;
	int	date;
	int	qe;
	int	r;
	int	seila;
	int	doido;
	int	t;
	int	bola;
	int	canela;
	int	um;
	int	dois;
	int	ttr;
}	ptr;

int key_mov(int keymov, void *tmp)
{
    ptr *vars = (ptr *)tmp;
    int width;
    int height;
    void    *img;
    printf("%c\n", keymov);
    if(keymov == 'w' || keymov == 'a'|| keymov == 's' || keymov == 'd')
    {
        img = mlx_xpm_file_to_image(vars->mlx, "./images/Dino.xpm", &width, &height);
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
	data.map.x = count_columns();
	data.map.y = count_line();


	int i;

	data.map.map = malloc((data.map.y + 1) * sizeof(char *));
	i = 0;
	while(i <= data.map.y)
	{
		data.map.map[i] = malloc((data.map.x + 1) * sizeof(char));
		data.map.map[i][data.map.x] = '\0';
		i++;
	}
	i = 0;
	while (i <= data.map.x)
	{
		data.map.map[data.map.y][i] = '\0';
		i++;
	}

// printf("x: %d\n", data.map.x); 13
// printf("y: %d\n", data.map.y); 5

i = 0;
int j = 0;
data.map.fd = open("./map.ber", O_RDONLY);
char	*line;
while (j < data.map.y)
{
	line = get_next_line(data.map.fd);
	i = 0;
	while (i < data.map.x)
	{
		data.map.map[j][i] = line[i];
		i++;
	}
	free(line);
	j++;
}
close(data.map.fd);


data.mlx_ptr = mlx_init();
data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.x * 50 , data.map.y * 50, "hi :)");
// int	teste1, teste2;


// data.img.wall = "./images/wall5.xpm";
// data.img.play = "./images/Dino.xpm";
i = 0;
j = 0;

while (data.map.map[i])
{
	j = 0;
	while (data.map.map[i][j])
	{
		//write(1, &data.map.map[i][j], 1);
		//j++;
		if(data.map.map[i][j] == '1')
		{
			// data.win_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.wall, &teste1, &teste2);
			// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.win_img, j * 50, i * 50);
			draw_background(&data, "./images/wall5.xpm",  j * 50, i * 50);
		}
		if(data.map.map[i][j] == 'P')
		{
			// data.win_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.play, &teste1, &teste2);
			// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.win_img, j * 50, i * 50);
			draw_background(&data, "./images/Dino.xpm",  j * 50, i * 50);
		}
		if(data.map.map[i][j] == 'C')
			draw_background(&data, "./images/coin.xpm", j * 50, i * 50);
		if(data.map.map[i][j] == 'E')
			draw_background(&data, "./images/Exit.xpm", j * 50, i * 50);
		j++;

	}
		//write(1, "\n", 1);
		i++;
}
	


	//printf("%d\n%d\n", data.map.x, data.map.y);

	
	//if (!data.mlx_ptr)
	//	return (1);
	
	//if (!data.win_ptr)
		//return (free(data.mlx_ptr), 1);	
    mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}