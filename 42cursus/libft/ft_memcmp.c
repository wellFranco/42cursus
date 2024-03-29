/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:47:32 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:47:36 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (n > i)
	{
		if ((((unsigned char *)s1)[i]) != (((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char test_00[15] = "to & jerry";
	char test_01[15] = "tom & jerry";

	printf("%d\n", ft_memcmp(test_00, test_01, 3));
}*/
