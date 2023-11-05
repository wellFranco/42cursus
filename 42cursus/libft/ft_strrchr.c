/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:15 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/01 14:33:10 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*aux;

	aux = NULL;
	while (*s)
	{
		if (*s == c)
			aux = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
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
