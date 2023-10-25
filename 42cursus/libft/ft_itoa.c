/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:30:37 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/25 18:14:55 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	sign;
	int		i;
	int		copy1;
	int		copy2;
	int		num;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
		i++;
	}
	copy1 = n;
	copy2 = n;
	while (n)
	{
		n = n/10;
		i++;
	}
	str = malloc((i + sign + 1) * sizeof(char));
	if (str)
	{
		str[i] = '\0';
		while (i)
		{
			i--;
			copy1 = copy1 / 10;
			num = copy2 - copy1 * 10;
			copy2 = copy2 / 10;
			str[i] = 48 + num;
		}
		if (str[0] == '0')
		{
			str[0] = '-';
		}
	}
	return (str);
}
/*int	main(void)
{
	printf("%s", ft_itoa(500));
	return (0);
}*/
