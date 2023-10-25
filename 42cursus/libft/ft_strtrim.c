/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:53:10 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/25 16:02:01 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strchr(const char *str, int c)
{
	while (*str && c != *str)
		str++;
	if (c == *str)
		return ((char *)str);
	return (0);
}

static size_t	strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (*s1 && strchr(set, *s1))
		s1++;
	i = strlen(s1);
	while (i && strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*int	main(void)
{
	char	s1[] = "oi, maninho";

	printf("%s", ft_strtrim(s1, "o"));
	return (0);
}*/
