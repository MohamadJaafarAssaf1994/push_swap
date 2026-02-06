/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:18 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/06 18:26:37 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_stack *stack)
{
	if (is_empty(stack))
	{
		printf("Stack is empty\n");
		return (-1);
	}
	return (stack->array[stack->top]);
}

void	swap(t_stack *stack, char c)
{
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->top;
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	ft_printf("%c%c\n", 's', c);
}

void	push_double(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a))
		return ;
	push(stack_a, pop(stack_b));
}

void	rotate(t_stack *stack, char c)
{
	int	temp;
	int	i;

	if (stack->top <= 0)
		return ;
	i = stack->top;
	temp = stack->array[stack->top];
	while (i > 0)
	{
		stack->array[i] = stack->array[--i];
	}
	stack->array[0] = temp;
	ft_printf("%c%c\n", 'r', c);
}

void	reverse_rotate(t_stack *stack, char c)
{
	int	temp;
	int	i;

	if (stack->top <= 0)
		return ;
	i = 0;
	temp = stack->array[0];
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = temp;
	ft_printf("%s%c\n", "rr", c);
}
