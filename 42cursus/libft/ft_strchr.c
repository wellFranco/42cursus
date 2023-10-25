/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:17:56 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/20 12:19:05 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && c != *str)
		str++;
	if (c == *str)
		return ((char *)str);
	return (0);
}
/*int		main(void)
{
	const char str[] = "tudo, ok";
	const char chr = 'o';
	char *rtn;

	rtn = ft_strchr(str, chr);

	printf("%s", rtn);

}*/
