/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:07:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/06 18:23:18 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_stack *stack, char c)
{
	int	top;
	int	middle;
	int	bottom;

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
		sort_stack_3(stack, c);
	}
}
