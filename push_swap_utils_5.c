/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:35:04 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/18 13:02:21 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_one(t_stack *a, t_stack *b, int index_a, int index_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < min((*b).top - index_b, (*a).top - index_a))
	{
		rotate_double(a, b, ft_printf);
		i++;
	}
	j = i;
	while (i < (*a).top - index_a)
	{
		rotate(a, 'a', ft_printf);
		i++;
	}
	while (j < (*b).top - index_b)
	{
		rotate(b, 'b', ft_printf);
		j++;
	}
	push_double(a, b, 'a', ft_printf);
}

void	operation_two(t_stack *a, t_stack *b, int index_a, int index_b)
{
	int	i;
	int	j;

	i = 0;
	while (i <= min(index_b, index_a))
	{
		reverse_rotate_double(a, b, ft_printf);
		i++;
	}
	j = i;
	while (i <= index_a)
	{
		reverse_rotate(a, 'a', ft_printf);
		i++;
	}
	while (j <= index_b)
	{
		reverse_rotate(b, 'b', ft_printf);
		j++;
	}
	push_double(a, b, 'a', ft_printf);
}

void	operation_three(t_stack *a, t_stack *b, int index_a, int index_b)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (i < (*a).top - index_a)
	{
		rotate(a, 'a', ft_printf);
		i++;
	}
	while (j <= index_b)
	{
		reverse_rotate(b, 'b', ft_printf);
		j++;
	}
	push_double(a, b, 'a', ft_printf);
}

void	operation_four(t_stack *a, t_stack *b, int index_a, int index_b)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (i < (*b).top - index_b)
	{
		rotate(b, 'b', ft_printf);
		i++;
	}
	while (j <= index_a)
	{
		reverse_rotate(a, 'a', ft_printf);
		j++;
	}
	push_double(a, b, 'a', ft_printf);
}

void	operation_five(t_stack *a)
{
	int	min;
	int	i;
	int	index;

	i = 0;
	min = min_of_stack(*a);
	index = index_by_element(min, *a);
	if (is_above(min, *a))
	{
		while (i < ((*a).top - index))
		{
			rotate(a, 'a', ft_printf);
			i++;
		}
	}
	else
	{
		while (i <= index)
		{
			reverse_rotate(a, 'a', ft_printf);
			i++;
		}
	}
}
