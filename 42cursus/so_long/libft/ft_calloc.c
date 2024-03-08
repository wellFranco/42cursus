/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:42:26 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/31 15:42:31 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*dst;

	total_size = size * nmemb;
	dst = malloc(total_size);
	if (!(dst))
		return (0);
	ft_memset (dst, 0, total_size);
	return (dst);
}
