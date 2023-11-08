/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:40:45 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/08 17:40:39 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count_hexa(int nb)
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

static void	ft_put_hexanb(int nb, char c)
{
	if (nb >= 16)
		ft_put_hexanb(nb / 16, c);
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
		{
			if (c == 'x')
				ft_putchar((nb - 10) + 'a');
			if (c == 'X')
				ft_putchar((nb - 10) + 'A');
		}
	}
}

int	ft_puthexa(int nb, char c)
{
	int	result;

	if (nb == 0)
	{
		result = ft_putchar(48);
		return (result);
	}
	ft_put_hexanb(nb, c);
	result = ft_count_hexa(nb);
	return (result);
}
