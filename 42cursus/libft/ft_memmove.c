/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:37:47 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:37:51 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const char *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i >= 0 && i < (int)n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
