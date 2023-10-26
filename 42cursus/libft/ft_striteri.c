/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:05:19 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/26 17:35:08 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (*s)
			f(i++, s++);
	}
}
/*void print_char(unsigned int i, char *c)
{
    printf("%u: %c\n", i, *c);
}

int main(void)
{
    char str[] = "Hello, World!";
    
    printf("Original String: %s\n", str);

    ft_striteri(str, print_char);

    return 0;
}*/
