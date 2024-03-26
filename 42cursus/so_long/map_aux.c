#include "so_long.h"

void	get_the_line(t_data *data, char *file)
{
	int fd;
	char *line;
	int	i;

	printf("%s\n", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
	line = get_next_line(fd);
	i = 0;
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("teste: %d\n", i);
	data->map.y = i;
	// printf("%s\n", line);
	close(fd);
}

void	get_the_columns(t_data *data, char *file)
{
	int fd;
	int	columns;
	char	*line;

	columns = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line[columns] != '\n')
		columns++;
	// printf("%\n", line);
	free(line);
	close(fd);
	data->map.x = columns;
}

