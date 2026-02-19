/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:45:17 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/19 15:35:05 by mohassaf         ###   ########.fr       */
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
		result[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	get_stack(t_stack *a, char **result)
{
	int		i;
	char	*str;

	if (!result)
		error_exit();
	if (!count_words(result))
	{
		free(result);
		error_exit();
	}
	a->top = ((i = count_words(result) - 1));
	while (i >= 0)
	{
		str = ft_itoa(ft_atoi(result[i]));
		if (!is_only_digits(result[i]) || ft_strncmp(str, result[i], 15) != 0)
		{
			free(str);
			free_split(result);
			error_exit();
		}
		free(str);
		a->array[a->top - i] = ft_atoi(result[i]);
		i--;
	}
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
