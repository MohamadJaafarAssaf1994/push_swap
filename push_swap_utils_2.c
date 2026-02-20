/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:18 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 13:47:09 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c, int (*f)(const char *str, ...))
{
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack_get(stack, stack->top);
	stack_set(stack, stack->top, stack_get(stack, stack->top - 1));
	stack_set(stack, stack->top - 1, temp);
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
	temp = stack_get(stack, stack->top);
	while (i > 0)
	{
		stack_set(stack, i, stack_get(stack, i - 1));
		i--;
	}
	stack_set(stack, 0, temp);
	if (*f != NULL)
		f("%c%c\n", 'r', c);
}

void	rotate_double(t_stack *a, t_stack *b, int (*f)(const char *str, ...))
{
	int	temp;
	int	i;

	if (a->top <= 0 || b->top <= -1)
		return ;
	i = a->top;
	temp = stack_get(a, a->top);
	while (i > 0)
	{
		stack_set(a, i, stack_get(a, i - 1));
		i--;
	}
	stack_set(a, 0, temp);
	i = b->top;
	temp = stack_get(b, b->top);
	while (i > 0)
	{
		stack_set(b, i, stack_get(b, i - 1));
		i--;
	}
	stack_set(b, 0, temp);
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
	temp = stack_get(stack, 0);
	while (i < stack->top)
	{
		stack_set(stack, i, stack_get(stack, i + 1));
		i++;
	}
	stack_set(stack, stack->top, temp);
	if (*f != NULL)
		f("%s%c\n", "rr", c);
}
