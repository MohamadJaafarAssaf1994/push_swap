/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:18 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/18 13:05:22 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, int (*f)(const char *str, ...))
{
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	if (*f != NULL)
		f("%c%c\n", 's', c);
}

void	push_double(t_stack *stack_a, t_stack *stack_b, char dest,
		int (*f)(const char *str, ...))
{
	if (is_empty(stack_b))
		return ;
	push(stack_a, pop(stack_b));
	if (*f != NULL)
		f("p%c\n", dest);
}

void	rotate(t_stack *stack, char c, int (*f)(const char *str, ...))
{
	int	temp;
	int	i;

	if (stack->top <= 0)
		return ;
	i = stack->top;
	temp = stack->array[stack->top];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
	if (*f != NULL)
		f("%c%c\n", 'r', c);
}

void	rotate_double(t_stack *a, t_stack *b, int (*f)(const char *str, ...))
{
	int	temp;
	int	i;

	if (a->top <= 0)
		return ;
	i = a->top;
	temp = a->array[a->top];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
	i = b->top;
	temp = b->array[b->top];
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
	if (*f != NULL)
		f("rr\n");
}

void	reverse_rotate(t_stack *stack, char c, int (*f)(const char *str, ...))
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
	if (*f != NULL)
		f("%s%c\n", "rr", c);
}
