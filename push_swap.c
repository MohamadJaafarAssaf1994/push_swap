/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:26:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 12:57:47 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**prepare_result(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (get_args(argc, argv));
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**result;

	result = prepare_result(argc, argv);
	stack_init(&a);
	stack_init(&b);
	get_and_validate_stack(&a, result, &b);
	if (a.top == 0 || is_sorted(a))
	{
		free_split(result);
		stack_free(&a);
		return (0);
	}
	push_all_a_to_b(&a, &b);
	push_swap(&a, &b);
	free_split(result);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
