/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:16:39 by wfranco           #+#    #+#             */
/*   Updated: 2023/11/08 15:27:46 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_nbr(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void	ft_put_unsinbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_put_unsinbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

int	ft_putunsint(unsigned int nb)
{
	int	result;

	if (nb == 0)
	{
		result = ft_putchar(48);
		return (result);
	}
	ft_put_unsinbr(nb);
	result = count_nbr(nb);
	return (result);
}
