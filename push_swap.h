/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:01:08 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/06 18:06:21 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 100

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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
void	swap(t_stack *stack, char c);
void	rotate(t_stack *stack, char c);
void	reverse_rotate(t_stack *stack, char c);
void	sort_stack_3(t_stack *stack, char c);
#endif
