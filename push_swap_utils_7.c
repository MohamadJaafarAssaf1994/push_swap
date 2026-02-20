/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:06:08 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/19 16:52:40 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (n < tab[i++])
			return (0);
	return (1);
}

int	is_min(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (n > tab[i++])
			return (0);
	return (1);
}

int	min_of_stack(t_stack a)
{
	int	min;
	int	i;

	min = stack_get(&a, 0);
	i = 1;
	while (i <= a.top)
	{
		if (min > stack_get(&a, i))
			min = stack_get(&a, i);
		i++;
	}
	return (min);
}

int	max_of_stack(t_stack a)
{
	int	max;
	int	i;

	max = stack_get(&a, 0);
	i = 1;
	while (i <= a.top)
	{
		if (max < stack_get(&a, i))
			max = stack_get(&a, i);
		i++;
	}
	return (max);
}

int	median(t_stack stack_a)
{
	long long	sum;
	int			index;

	index = 0;
	sum = 0;
	while (index <= stack_a.top)
	{
		sum += stack_get(&stack_a, index);
		index++;
	}
	return ((int)(sum / (stack_size(&stack_a))));
}
