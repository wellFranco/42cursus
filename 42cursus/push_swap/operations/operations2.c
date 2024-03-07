/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:11:37 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/07 18:11:43 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*remove;

	if (*a)
	{
		remove = remove_first(a);
		insert_first(b, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "pb\n", 3);
	return (1);
}

int	ra(t_stack **a, int print)
{
	t_stack	*remove;

	if (*a && (*a)->next)
	{
		remove = remove_first(a);
		insert_last(a, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **b, int print)
{
	t_stack	*remove;

	if (*b && (*b)->next)
	{
		remove = remove_first(b);
		insert_last(b, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
	return (1);
}
