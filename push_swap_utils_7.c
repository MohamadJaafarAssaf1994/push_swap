/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:06:08 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/16 18:43:21 by mohassaf         ###   ########.fr       */
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

	min = a.array[0];
	i = 1;
	while (i <= a.top)
	{
		if (min > a.array[i])
			min = a.array[i];
		i++;
	}
	return (min);
}

int	max_of_stack(t_stack a)
{
	int	max;
	int	i;

	max = a.array[0];
	i = 1;
	while (i <= a.top)
	{
		if (max < a.array[i])
			max = a.array[i];
		i++;
	}
	return (max);
}

int	median(t_stack stack_a)
{
	int	sum;
	int	index;

	index = 0;
	sum = 0;
	while (index <= stack_a.top)
	{
		sum += stack_a.array[index];
		index++;
	}
	return (sum / (stack_a.top + 1));
}
