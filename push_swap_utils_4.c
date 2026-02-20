/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:00:17 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 11:56:14 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_above(int element, t_stack stack)
{
	int	index;

	index = index_by_element(element, stack);
	if (index >= stack.top / 2)
		return (1);
	return (0);
}

int	is_under(int element, t_stack stack)
{
	int	index;

	index = index_by_element(element, stack);
	if (index <= stack.top / 2)
		return (1);
	return (0);
}

int	total_cost(int index_b, t_stack a, t_stack b)
{
	int	index_a;
	int	target_node_a;
	int	a_moves;
	int	b_moves;
	int	extra;

	target_node_a = smallest_biggest_in_stack_a(a, b, index_b);
	index_a = index_by_element(target_node_a, a);
	if (is_above(target_node_a, a) && is_above(stack_get(&b, index_b), b))
	{
		a_moves = a.top - index_a;
		b_moves = b.top - index_b;
		extra = abs(b.top - index_b - a.top + index_a);
		return (min(b_moves, a_moves) + extra);
	}
	if (is_under(target_node_a, a) && is_under(stack_get(&b, index_b), b))
	{
		extra = abs(index_b - index_a);
		return (min(index_b, index_a) + extra + 1);
	}
	if (is_above(target_node_a, a) && !is_above(stack_get(&b, index_b), b))
		return (a.top - index_a + index_b + 1);
	return (b.top - index_b + index_a + 1);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}
