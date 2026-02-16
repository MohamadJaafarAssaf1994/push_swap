/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:07:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/16 18:42:08 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack *stack, char c)
{
	int	top;
	int	middle;
	int	bottom;

	if (stack->top == 1)
	{
		case_one(stack);
		return ;
	}
	top = stack->array[2];
	middle = stack->array[1];
	bottom = stack->array[0];
	if (top <= middle && middle <= bottom)
		return ;
	if (top <= middle && bottom <= top)
		reverse_rotate(stack, c);
	else if (middle <= top && top <= bottom)
		swap(stack, c);
	else if (bottom <= top && bottom >= middle)
		rotate(stack, c);
	else
	{
		swap(stack, c);
		sort_stack_a(stack, c);
	}
}

void	push_all_a_to_b(t_stack *a, t_stack *b)
{
	while (a->top > 2)
	{
		if (a->array[a->top] <= median(*a))
			push_double(b, a, 'b');
		else
		{
			push_double(b, a, 'b');
			rotate(b, 'b');
		}
	}
}

int	smallest_biggest_in_stack_a(t_stack a, t_stack b, int index_element_stack_b)
{
	int	i;
	int	diff;

	i = 0;
	if (is_max(b.array[index_element_stack_b], a.array, a.top + 1)
		|| is_max(b.array[index_element_stack_b], a.array, a.top + 1))
		return (min_of_stack(a));
	diff = max_of_stack(a) - b.array[index_element_stack_b];
	while (i <= a.top)
	{
		if (diff > (a.array[i] - b.array[index_element_stack_b]) && a.array[i]
			- b.array[index_element_stack_b] > 0)
			diff = a.array[i] - b.array[index_element_stack_b];
		i++;
	}
	return (diff + b.array[index_element_stack_b]);
}

void	reverse_rotate_double(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->top <= 0)
		return ;
	i = 0;
	temp = a->array[0];
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->top] = temp;
	i = 0;
	temp = b->array[0];
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->top] = temp;
	ft_printf("rrr\n");
}

int	index_by_element(int element, t_stack stack)
{
	int	index;

	index = 0;
	if (stack.top == -1)
		return (-1);
	while (index <= stack.top)
	{
		if (stack.array[index] == element)
			return (index);
		index++;
	}
	return (-1);
}
