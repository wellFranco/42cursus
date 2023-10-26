/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:30:37 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/26 14:02:25 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_n(int n, int i)
{
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_sign(int *sign, int *n, int *i)
{
	*sign = 1;
	*n *= -1;
	++*i;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;
	int		copy;

	sign = 0;
	i = 0;
	if (n < 0)
		ft_sign(&sign, &n, &i);
	copy = n;
	i = size_n(n, i);
	str = malloc((i + sign + 1) * sizeof(char));
	if (str)
	{
		str[i] = '\0';
		while (i--)
		{
			n = n / 10;
			str[i] = 48 + copy - n * 10;
			copy = copy / 10;
		}
		if (str[0] == '0')
			str[0] = '-';
	}
	return (str);
}
/*int	main(void)
{
	printf("%s", ft_itoa(-500));
	return (0);
}*/
