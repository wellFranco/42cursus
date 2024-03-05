/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:03:31 by wfranco           #+#    #+#             */
/*   Updated: 2024/02/07 16:06:38 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int		nbr;
	int		index;
	struct	s_stack	*next;
	struct	s_stack *prev;
}	t_stack;

#endif
