/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:04:10 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/23 16:49:53 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	i;
	char 	*str;

	str = malloc((len - start) * (sizeof(char *)));
	if (str)
	{
		i = 0;
		while (start < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}
/*int	main(void)
{
	char str[] = "Minecraft";
	char *dst;

	dst = ft_substr(str, 2, 10);
	printf("%s", dst);
	return (0);
}*/
