/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:32 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/18 18:05:58 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	d_size;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	d_size = d_len;
	i = 0;
	while (src[i] != '\0')
	{
		dst[d_size] = src[i];
		d_size++;
		i++;
	if (d_size == size - 1)
		break;
	}
	dst[d_size] = '\0';
	return (d_len + s_len);
}
int	main(void)
{
	char source[] 
}
