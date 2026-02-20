/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:07:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 13:47:15 by mohassaf         ###   ########.fr       */
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
	top = stack_get(stack, 2);
	middle = stack_get(stack, 1);
	bottom = stack_get(stack, 0);
	if (top <= middle && middle <= bottom)
		return ;
	if (top <= middle && bottom <= top)
		reverse_rotate(stack, c, ft_printf);
	else if (middle <= top && top <= bottom)
		swap(stack, c, ft_printf);
	else if (bottom <= top && bottom >= middle)
		rotate(stack, c, ft_printf);
	else
	{
		swap(stack, c, ft_printf);
		sort_stack_a(stack, c);
	}
}

void	push_all_a_to_b(t_stack *a, t_stack *b)
{
	stack_init(b);
	while (a->top > 2)
	{
		if (stack_get(a, a->top) <= median(*a))
			push_double(b, a, 'b', ft_printf);
		else
		{
			push_double(b, a, 'b', ft_printf);
			rotate(b, 'b', ft_printf);
		}
	}
	sort_stack_a(a, 'a');
}

int	smallest_biggest_in_stack_a(t_stack a, t_stack b, int index_element_stack_b)
{
	int	i;
	int	diff;

	i = 0;
	if (is_max(b.array[index_element_stack_b], a.array, stack_size(&a))
		|| is_min(b.array[index_element_stack_b], a.array, stack_size(&a)))
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

void	reverse_rotate_double(t_stack *a, t_stack *b, int (*f)(const char *str,
			...))
{
	int	temp;
	int	i;

	if (a->top <= 0 || b->top <= -1)
		return ;
	i = 0;
	temp = stack_get(a, 0);
	while (i < a->top)
	{
		stack_set(a, i, stack_get(a, i + 1));
		i++;
	}
	stack_set(a, a->top, temp);
	i = 0;
	temp = stack_get(b, 0);
	while (i < b->top)
	{
		stack_set(b, i, stack_get(b, i + 1));
		i++;
	}
	stack_set(b, b->top, temp);
	if (*f != NULL)
		f("rrr\n");
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
