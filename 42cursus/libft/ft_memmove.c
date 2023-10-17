/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:22:18 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/17 17:31:50 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const char *src, size_t n)
{
	unsigned char	*x;
	const unsigned char	*y;

	x = dest;
	y = src;
	if (x < y)
	{
		while (n--)
		{
			*x++ = *y++;
		}
	}
	else
	{
		while (n--)
		{
			x[n] = y[n];
		}
	}
	return (dest);
}
