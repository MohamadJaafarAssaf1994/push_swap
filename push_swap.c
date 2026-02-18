/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:26:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/17 18:46:49 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!check_stack(a))
	{
		free_split(result);
		error_exit();
	}
	if (a.top == 0 || is_sorted(a))
	{
		free_split(result);
		return (1);
	}
	push_all_a_to_b(&a, &b);
	push_swap(&a, &b);
	free_split(result);
	return (0);
}
