/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:25 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 17:56:44 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*aux;

	aux = NULL;
	while (*str)
	{
		if (*str == c)
			aux = str;
		str++;
	}
	if (*str == c)
		return ((char *)str);
	else
		return ((char *)aux);
}
/*int     main(void)
{
    const char str[] = "tudo, ok";
	const char chr = 'o';
	char *rtn;

	rtn = ft_strrchr(str, chr);

	printf("%s", rtn);
}*/
