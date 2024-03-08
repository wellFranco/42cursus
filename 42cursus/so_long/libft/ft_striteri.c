/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:46:00 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:46:08 by wfranco          ###   ########.fr       */
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
