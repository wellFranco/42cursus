/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:36:55 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 19:37:55 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	
	if (!big && !len)
		return (NULL);
	if (!little)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[j] == little[j]) && little[j]!= '\0' && j <= len )
			{
				if (little[j] != '\0')
					return ((char *)big);
				j++;
			}
		i++;
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
