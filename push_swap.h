/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:01:08 by mohassaf          #+#    #+#             */
/*   Updated: 2026/01/23 17:51:34 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 100

# include <stdbool.h>

typedef struct s_stack
{
	int	array[MAX_SIZE];
	int	top;
}		t_stack;

void	initialize(t_stack *stack);
bool	is_empty(t_stack *stack);
bool	is_full(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
#endif
