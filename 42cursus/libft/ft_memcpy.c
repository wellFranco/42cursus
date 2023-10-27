/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:25:33 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 17:36:02 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*x;
	const char	*y;

	x = dest;
	y = src;
	if (!x && !y)
		return (NULL);
	while (n > 0)
	{
		*x = *y;
		x++;
		y++;
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	const char str[] = "hello world\n";
	char buf[0xff];

	ft_memcpy(buf, str, sizeof(str));
	printf("%s", buf);
	return (0);
}*/
