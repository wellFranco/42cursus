/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:41:07 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:41:13 by wfranco          ###   ########.fr       */
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
