/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:26:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/06 18:22:11 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	push_swap(t_stack a)
{

}*/

int main(void)
{
	t_stack stack;

	stack.top = 2;
	stack.array[2] = 7;
	stack.array[1] = 8;
	stack.array[0] = 3;

	sort_stack_3(&stack, 'a');
	ft_printf("%d, %d, %d", stack.array[0], stack.array[1], stack.array[2]);

}
