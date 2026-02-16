/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:26:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/16 18:49:06 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <time.h>

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

int	count_words(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
		i++;
	return (i);
}

char	**get_args(int argc, char *argv[])
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * argc);
	if (!result)
		return (NULL);
	while (i < argc - 1)
	{
		result[i] = argv[i + 1];
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	get_stack(t_stack *a, char **result)
{
	int	i;

	if (!result)
		error_exit();
	if (!count_words(result))
		error_exit();
	i = count_words(result) - 1;
	a->top = i;
	while (i >= 0)
	{
		if (!is_only_digits(result[i]))
			error_exit();
		if (ft_strncmp(ft_itoa(ft_atoi(result[i])), result[i], 15) != 0)
			error_exit();
		a->array[a->top - i] = ft_atoi(result[i]);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**result;

	if (argc == 1)
		return (0);
	if (argc == 2)
		result = ft_split(argv[1], ' ');
	else
		result = get_args(argc, argv);
	get_stack(&a, result);
	check_stack(a);
	if (a.top == 0)
		return (1);
	b.top = -1;
	if (is_sorted(a))
	{
		free(result);
		return (0);
	}
	push_all_a_to_b(&a, &b);
	sort_stack_a(&a, 'a');
	push_swap(&a, &b);
	free(result);
	return (0);
}
