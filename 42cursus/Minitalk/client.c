/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:25:40 by wfranco           #+#    #+#             */
/*   Updated: 2024/01/06 15:44:12 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char sign)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((sign >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("Number of arguments invalid!\n");
	return (0);
}
