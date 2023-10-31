/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:46:20 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:46:40 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[2] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		}
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*int	main(void)
{
	char test_00[15] = "to & jerry";
	char test_01[15] = "tom & jerry";

	printf("%d\n", ft_strncmp(test_00, test_01, 1));
}*/
