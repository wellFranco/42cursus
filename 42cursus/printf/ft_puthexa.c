/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:40:45 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/13 14:35:34 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hexa(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

static void	ft_put_hexanb(unsigned int nb, char c)
{
	if (nb >= 16)
	{
		ft_put_hexanb(nb / 16, c);
		ft_put_hexanb(nb % 16, c);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
		{
			if (c == 'x')
				ft_putchar(nb - 10 + 'a');
			if (c == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}

int	ft_puthexa(unsigned int nb, char c)
{
	int	result;

	result = 0;
	if (nb == 0)
	{
		result += ft_putchar(48);
		return (result);
	}
	result += ft_count_hexa(nb);
	ft_put_hexanb(nb, c);
	return (result);
}
