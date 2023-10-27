/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:32 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 19:10:03 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	d_size;

	s_len = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	d_size = d_len;
	if (size <= d_size)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && d_size < size - 1)
	{
		dst[d_size] = src[i];
		d_size++;
		i++;
	}
	dst[d_size] = '\0';
	return (d_len + s_len);
}
/*int	main(void)
{
	char source[] = "tom &";
	char dst[] = "jerry";
	
	printf("%ld", ft_strlcat(source, dst, sizeof(source)));
	return (0);
}*/
