/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:01:08 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/19 16:14:15 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 10000

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_stack
{
	int	array[MAX_SIZE];
	int	top;
}		t_stack;

bool	is_empty(t_stack *stack);
bool	is_full(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack, char c, int (*f)(const char *str, ...));
void	rotate(t_stack *stack, char c, int (*f)(const char *str, ...));
void	reverse_rotate(t_stack *stack, char c, int (*f)(const char *str, ...));
void	sort_stack_a(t_stack *stack, char c);
void	push_double(t_stack *stack_a, t_stack *stack_b, char dest,
			int (*f)(const char *str, ...));
void	push_all_a_to_b(t_stack *a, t_stack *b);
int		is_max(int n, int *tab, int size);
int		is_min(int n, int *tab, int size);
int		min_of_stack(t_stack a);
int		max_of_stack(t_stack a);
int		smallest_biggest_in_stack_a(t_stack a, t_stack b,
			int index_element_stack_b);
int		index_by_element(int element, t_stack stack);
int		is_above(int element, t_stack stack);
int		is_under(int element, t_stack stack);
int		min(int a, int b);
int		abs(int a);
int		total_cost(int index_element_stack_b, t_stack a, t_stack b);
int		chosen_element_b_index(t_stack a, t_stack b);
void	rotate_double(t_stack *a, t_stack *b, int (*f)(const char *str, ...));
void	reverse_rotate_double(t_stack *a, t_stack *b, int (*f)(const char *str,
				...));
void	operation_one(t_stack *a, t_stack *b, int index_a, int index_b);
void	operation_two(t_stack *a, t_stack *b, int index_a, int index_b);
void	operation_three(t_stack *a, t_stack *b, int index_a, int index_b);
void	operation_four(t_stack *a, t_stack *b, int index_a, int index_b);
void	operation_five(t_stack *a);
int		count_words(char **result);
int		median(t_stack stack_a);
int		is_only_digits(char *str);
void	case_one(t_stack *a);
char	**get_args(int argc, char *argv[]);
void	error_exit(void);
void	get_stack(t_stack *a, char **result);
int		check_stack(t_stack a);
int		is_sorted(t_stack a);
void	free_split(char **tab);
void	push_swap(t_stack *a, t_stack *b);

#endif
