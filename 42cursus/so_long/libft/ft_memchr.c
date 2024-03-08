/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:50 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:44:56 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char)c) == (((unsigned char *)s)[i]))
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*int main (void) {
   const char str[] = "https://www.minecraft.com";
   const char ch = 't';
   char *ret;

   ret = ft_memchr(str, ch, 2);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
