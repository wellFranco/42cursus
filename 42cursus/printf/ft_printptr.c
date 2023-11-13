/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:09:00 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/13 14:25:29 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_ptr(unsigned long long nb)
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

static void	ft_put_ptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
			ft_putchar((nb - 10) + 'a');
	}
}

int	ft_printptr(unsigned long long nb)
{
	int	result;

	if (nb == 0)
	{
		result = ft_putstr("(nil)");
		return (result);
	}
	result = 0;
	result += write(1, "0x", 2);
	ft_put_ptr(nb);
	result += ft_count_ptr(nb);
	return (result);
}
