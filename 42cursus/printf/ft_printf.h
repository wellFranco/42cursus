/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:57 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/13 14:50:08 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr(int nb);

int	ft_puthexa(unsigned int nb, char c);

int	ft_putunsint(unsigned int nb);

int	ft_printptr(unsigned long long nb);

int	ft_printf(const char *s, ...);

#endif
