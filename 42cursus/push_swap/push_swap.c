/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:05:28 by wfranco           #+#    #+#             */
/*   Updated: 2024/03/07 18:14:20 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 2 && i--)
		argv = ft_split(argv[1], ' ');
	if (validation_part1(argv, i) || validation_part2(argv, &a, i))
	{
		if (argc == 2)
			free_split(argv);
		return (!write(1, "Error\n", 6));
	}
	if (argc == 2)
		free_split(argv);
	index_list(&a);
	sort_list(&a, &b);
	free_list(&a);
	return (0);
}
