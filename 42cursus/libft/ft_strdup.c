/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:29:16 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/23 15:02:39 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s) + 1);
	if (!(s2))
		return (0);
	ft_memcpy(s2, s, ft_strlen(s) + 1);
	return (s2);
}
/*int	main(void)
{
	char	test_00[] = "tom & jerry";
	char	*copy;

	copy = ft_strdup(test_00);

	if (copy == NULL)
		return (1);
	printf("%s", copy);
	return (0);
}*/
