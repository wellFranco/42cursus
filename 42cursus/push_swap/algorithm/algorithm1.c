/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:05:54 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/07 18:05:59 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_max_of_bits(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb >> 1;
	}
	return (i);
}

int	index_max(t_stack *stake)
{
	t_stack	*aux;
	int		max;

	max = -1;
	aux = stake;
	while (aux)
	{
		if (max < aux->index)
			max = aux->index;
		aux = aux->next;
	}
	return (max);
}

void	reposition_small_node(t_stack **a, t_stack n_small, int count)
{
	int		param;
	int		size_list;
	t_stack	*aux;

	size_list = size_stack(a);
	param = size_list / 2;
	aux = *a;
	while (aux->n != n_small.n)
	{
		count++;
		aux = aux->next;
	}
	if (count < param)
	{
		while ((*a)->n != n_small.n)
			ra(a, 1);
	}
	else
	{
		while ((*a)->n != n_small.n)
			rra(a, 1);
	}
}

t_stack	*small_node(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*n_small;
	int		small;

	aux = stack;
	small = size_stack(&stack);
	while (aux)
	{
		if (small > aux->index)
		{
			n_small = aux;
			small = aux->index;
		}
		aux = aux->next;
	}
	return (n_small);
}

void	index_list(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*small;
	int		i;
	int		size_list;
	int		nb;

	i = 0;
	size_list = size_stack(stack);
	while (i < size_list)
	{
		nb = 2147483647;
		aux = *stack;
		while (aux)
		{
			if (nb >= aux->n && aux->index == -1)
			{
				small = aux;
				nb = aux->n;
			}
			aux = aux->next;
		}
		small->index = i;
		i++;
	}
}
