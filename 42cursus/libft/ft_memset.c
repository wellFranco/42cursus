/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:33:50 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/27 15:01:03 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = c;
		x++;
		n--;
	}
	return (s);
}
/*int     main(void)
{
	        char buf[50];

		        ft_memset(buf, 'A', 20);
			        printf("%s", buf);
				        return (0);
					    
}*/
