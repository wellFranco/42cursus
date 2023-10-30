/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:36:55 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/30 14:35:47 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len--)
	{
		j = 0;
		while (*(big + j) == *(little + j) && *(little + j) && j <= len )
			{
				if (!*(little + j + 1))
					return ((char *)big);
				j++;
			}
		big++;
	}
	return (NULL);
}
/*int main (void) {
   const char big[20] = "smartfit";
   const char little[10] = "fit";
   char *ret;

   ret = ft_strnstr(big, little, sizeof(big));

   printf("The substring is: %s\n", ret);

   return(0);
}*/
