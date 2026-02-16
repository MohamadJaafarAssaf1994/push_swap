/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:18 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/16 18:47:52 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (stack->top == (MAX_SIZE - 1));
}

void	push(t_stack *stack, int value)
{
	if (is_full(stack))
	{
		printf("Stack Overflow\n");
		return ;
	}
	stack->array[++stack->top] = value;
}

int	pop(t_stack *stack)
{
	int	popped;

	if (is_empty(stack))
	{
		printf("Stack Underflow\n");
		return (-1);
	}
	popped = stack->array[stack->top];
	stack->top--;
	return (popped);
}
