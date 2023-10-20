/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:23:06 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/20 12:25:10 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)(*s1) - (int)(*s2));
}
/*int	main(void)
{
	char test_00[15] = "to & jerry";
	char test_01[15] = "tom & jerry";

	printf("%d\n", ft_strncmp(test_00, test_01, 1));
}*/
