/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:18 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 11:28:56 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

bool	is_full(t_stack *stack)
{
	if (stack->capacity == 0)
		return (false);
	return (stack->top == (stack->capacity - 1));
}

void	push(t_stack *stack, int value)
{
	int	old_cap;
	int	*new_arr;

	if (stack->top == -1)
	{
		stack->capacity = 1;
		stack->array = malloc(sizeof(int) * stack->capacity);
		if (!stack->array)
			error_exit();
	}
	else if (stack->top == stack->capacity - 1)
	{
		old_cap = stack->capacity;
		stack->capacity += 1;
		new_arr = malloc(sizeof(int) * stack->capacity);
		if (!new_arr)
			error_exit();
		ft_memcpy(new_arr, stack->array, sizeof(int) * old_cap);
		free(stack->array);
		stack->array = new_arr;
	}
	stack->top++;
	stack_set(stack, stack->top, value);
}

int	pop(t_stack *stack)
{
	int	popped;

	if (is_empty(stack))
	{
		printf("Stack Underflow\n");
		return (-1);
	}
	popped = stack_get(stack, stack->top);
	stack->top--;
	return (popped);
}
