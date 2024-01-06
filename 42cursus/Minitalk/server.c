/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:06:49 by wfranco           #+#    #+#             */
/*   Updated: 2024/01/06 14:47:15 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_signal(int sig)
{
	static int	bin;
	static char	c;

	if (sig == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	else
		c = c << 1;
	bin ++;
	if (bin == 8)
	{
		ft_putchar(c);
		c = 0;
		bin = 0;
	}
}

int	main(void)
{
	ft_putstr("Server PID -> ");
	ft_putnbr(getpid());
	ft_putstr("\n\n");
	while (1)
	{
		signal(SIGUSR1, check_signal);
		signal(SIGUSR2, check_signal);
		pause();
	}
	return (0);
}
