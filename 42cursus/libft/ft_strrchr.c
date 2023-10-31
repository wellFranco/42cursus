/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:15 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:36:19 by wfranco          ###   ########.fr       */
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
