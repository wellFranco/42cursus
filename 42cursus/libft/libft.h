/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:13 by wfranco           #+#    #+#             */
/*   Updated: 2023/10/17 15:29:32 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_isprint(int c);

size_t	ft_strlen(const char *str);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
