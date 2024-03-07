/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_assist1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:07:00 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/07 18:07:03 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_duplicate(t_stack **no)
{
	t_stack	*assist1;
	t_stack	*assist2;
	int		n;
	int		count;

	assist1 = *no;
	while (assist1)
	{
		assist2 = *no;
		n = assist1->n;
		count = 0;
		while (assist2)
		{
			if (n == assist2->n)
				count++;
			if (count > 1)
				return (1);
			assist2 = assist2->next;
		}
		assist1 = assist1->next;
	}
	return (0);
}

int	validation_part1(char **argv, int i)
{
	int		j;
	int		n;

	while (argv[i])
	{
		j = 0;
		n = 0;
		while (argv[i][j] || j == 0)
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') &&
				argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				n++;
			if (n && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation_part2(char **argv, t_stack **a, int i)
{
	long	n;

	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_list(a));
		insert_last(a, n, -1);
		i++;
	}
	if (search_duplicate(a))
		return (free_list(a));
	return (0);
}

int	free_list(t_stack **no)
{
	t_stack	*assist;

	assist = *no;
	while (assist)
	{
		*no = (*no)->next;
		free(assist);
		assist = *no;
	}
	return (1);
}

int	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (1);
}
