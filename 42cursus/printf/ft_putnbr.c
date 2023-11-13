/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:29 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/09 15:49:38 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_nb(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	ft_putnb(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnb(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnb(-nb);
	}
	else if (nb > 9)
	{
		ft_putnb(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_putnbr(int nb)
{
	int	result;

	if (nb == 0)
	{
		result = ft_putchar(48);
		return (result);
	}
	ft_putnb(nb);
	result = ft_size_nb(nb);
	return (result);
}
