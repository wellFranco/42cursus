/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:36:55 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/20 18:12:10 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j])
			{
				i++;
				j++;
				if (little[j] != '\0')
					return ((char *)&big[i - j]);
			}
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
