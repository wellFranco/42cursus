/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:20:51 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/13 14:05:42 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char s)
{
	int	len_format;

	len_format = 0;
	if (s == 'c')
		len_format += ft_putchar(va_arg(args, int));
	else if (s == 's')
		len_format += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		len_format += ft_printptr(va_arg(args, unsigned long long));
	else if (s == 'd' || s == 'i')
		len_format += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		len_format += ft_putunsint(va_arg(args, unsigned int));
	else if (s == 'x')
		len_format += ft_puthexa(va_arg(args, unsigned int), s);
	else if (s == 'X')
		len_format += ft_puthexa(va_arg(args, unsigned int), s);
	else if (s == '%')
		len_format += ft_putchar('%');
	return (len_format);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += ft_format(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
