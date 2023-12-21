/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:11 by wfranco           #+#    #+#             */
/*   Updated: 2023/12/21 15:42:02 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler(int num)
{
	write(STDOUT_FILENO, "I won't die!\n", 13);
}

void	seghandler(int num)
{
	write(STDOUT_FILENO, "Seg Fault!\n", 10);
}

int	main()
{
	struct	sigaction sa;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);

	while (1)
	{
		printf ("esperando alguma coisa. %d\n", getpid());
		sleep(1);
	}
}
