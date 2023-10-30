/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:37 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/30 20:11:55 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count( char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s == 0)
		return (0);
	while (s[i] && s[i] ==c)
		i++;
	while (s[i])
	{
		cnt++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;
	size_t	len;
	
	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	if (s == 0)
		return (0);
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free(char **array, size_t i)
{
	while (i  > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	cnt;
	char	**result;

	if (s == 0)
		return (0);
	cnt = ft_count(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!result)
		return(0);
	i = 0;
	while (i < cnt)
	{
		while(*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		result[i] = ft_strndup(s, len);
		if (!result[i])
		{
			ft_free(result, i);
			return (0);
		}
		s += len;
		i++;
	}
	result[cnt] = '\0';
	return (result);
}
