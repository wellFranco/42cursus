/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:07:24 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/07 18:07:27 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_first(t_stack **no, int n, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->n = n;
	new->index = index;
	new->next = *no;
	new->previous = NULL;
	if (*no)
		(*no)->previous = new;
	*no = new;
}

void	insert_last(t_stack **no, int n, int index)
{
	t_stack	*new;
	t_stack	*assist;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->n = n;
	new->index = index;
	new->next = NULL;
	if (!*no)
	{
		*no = new;
		new->previous = NULL;
	}
	else
	{
		assist = *no;
		while (assist->next)
			assist = assist->next;
		assist->next = new;
		new->previous = assist;
	}
}
