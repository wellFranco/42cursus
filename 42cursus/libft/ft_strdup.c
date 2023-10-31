/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:43:30 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:43:34 by wfranco          ###   ########.fr       */
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
