/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:00:00 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/19 17:00:10 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->array = NULL;
	s->top = -1;
	s->capacity = 0;
}

void	stack_free(t_stack *s)
{
	if (s->array)
		free(s->array);
	s->array = NULL;
	s->top = -1;
	s->capacity = 0;
}

int	stack_size(t_stack *s)
{
	if (!s)
		return (0);
	return (s->top + 1);
}

int	stack_get(t_stack *s, int index)
{
	if (!s || !s->array || index < 0 || index > s->top)
		error_exit();
	return (s->array[index]);
}

void	stack_set(t_stack *s, int index, int value)
{
	if (!s || !s->array || index < 0 || index > s->top)
		error_exit();
	s->array[index] = value;
}
