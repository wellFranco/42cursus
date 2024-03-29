/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:31:47 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/29 09:45:28 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], ".ber", 4))
	{
		write(1, "Error : extensão inválida.\n", 27);
		exit (1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nMapa inválido.\n", 21);
		exit (1);
	}
	close(fd);
}
