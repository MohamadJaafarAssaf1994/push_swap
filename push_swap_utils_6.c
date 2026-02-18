/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:44:02 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/18 12:35:51 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chosen_element_b_index(t_stack a, t_stack b)
{
	int	i;
	int	min_cost;
	int	j;

	i = b.top;
	j = 0;
	min_cost = 100000;
	while (i >= 0)
	{
		if (total_cost(i, a, b) < min_cost)
		{
			min_cost = total_cost(i, a, b);
			j = i;
		}
		i--;
	}
	return (j);
}

int	is_only_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	case_one(t_stack *a)
{
	if (a->array[0] > a->array[1])
		return ;
	swap(a, 'a', ft_printf);
}

int	check_stack(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.top)
	{
		j = i + 1;
		while (j <= a.top)
		{
			if (a.array[i] == a.array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.top)
	{
		if (a.array[i] < a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
