/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:33:46 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/23 14:34:04 by wfranco          ###   ########.fr       */
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
