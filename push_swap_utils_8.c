/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:45:17 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 13:03:18 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	index_a;
	int	index_b;
	int	target_node_a;

	index_a = 0;
	index_b = 0;
	if ((*b).top == -1)
		return ;
	while ((*b).top != -1)
	{
		index_b = chosen_element_b_index(*a, *b);
		target_node_a = smallest_biggest_in_stack_a(*a, *b, index_b);
		index_a = index_by_element(target_node_a, *a);
		if (is_above(target_node_a, *a) && is_above((*b).array[index_b], *b))
			operation_one(a, b, index_a, index_b);
		else if (is_under(target_node_a, *a) && is_under((*b).array[index_b],
				*b))
			operation_two(a, b, index_a, index_b);
		else if (is_above(target_node_a, *a) && !is_above((*b).array[index_b],
				*b))
			operation_three(a, b, index_a, index_b);
		else
			operation_four(a, b, index_a, index_b);
	}
	operation_five(a);
}

static void	validate_and_alloc(t_stack *a, char **result)
{
	int	count;

	if (!result)
		error_exit();
	count = count_words(result);
	if (!count)
	{
		stack_free(a);
		free(result);
		error_exit();
	}
	count--;
	a->capacity = count + 1;
	a->array = malloc(sizeof(int) * a->capacity);
	if (!a->array)
		error_exit();
	a->top = count;
}

static void	validate_and_set(t_stack *a, int pos, char *s, char **result)
{
	char	*str;

	str = ft_itoa(ft_atoi(s));
	if (!is_only_digits(s) || ft_strncmp(str, s, 15) != 0)
	{
		stack_free(a);
		free(str);
		free_split(result);
		error_exit();
	}
	free(str);
	stack_set(a, pos, ft_atoi(s));
}

void	get_and_validate_stack(t_stack *a, char **result, t_stack *b)
{
	int	i;

	validate_and_alloc(a, result);
	i = a->top;
	while (i >= 0)
	{
		validate_and_set(a, a->top - i, result[i], result);
		i--;
	}
	if (!check_stack_double(*a))
	{
		stack_free(a);
		stack_free(b);
		free_split(result);
		error_exit();
	}
}

void	swap_double(t_stack *a, t_stack *b)
{
	swap(a, 'a', NULL);
	swap(b, 'b', NULL);
}
