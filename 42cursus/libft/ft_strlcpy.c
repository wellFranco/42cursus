/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:58:44 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 18:33:33 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
/*int main(void)
{
   char source[] = "Hello, World!";
   i char destination[20];

    size_t copied_len = ft_strlcpy(destination, source, sizeof(destination));

    printf("Destination: %s\n", destination);
    printf("Copied Length: %zu\n", copied_len);

    return (0);

}*/
