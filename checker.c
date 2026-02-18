/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:24:20 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/18 13:02:55 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_double(t_stack *a, t_stack *b)
{
	swap(a, 'a', NULL);
	swap(b, 'b', NULL);
}

static void	execute(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "ra\n", 5))
		rotate(a, 'a', NULL);
	else if(!ft_strncmp(line, "rb\n", 5))
		rotate(b, 'b', NULL);
	else if (!ft_strncmp(line, "sa\n", 5))
		swap(a, 'a', NULL);
	else if(!ft_strncmp(line, "sb\n", 5))
		swap(b, 'b', NULL);
	else if (!ft_strncmp(line, "pa\n", 5))
		push_double(a, b, 'a', NULL);
	else if(!ft_strncmp(line, "pb\n", 5))
		push_double(b, a, 'b', NULL);
	else if(!ft_strncmp(line, "rra\n", 5))
		reverse_rotate(a, 'a', NULL);
	else if(!ft_strncmp(line, "rrb\n", 5))
		reverse_rotate(b, 'b', NULL);
	else if(!ft_strncmp(line, "rr\n", 5))
		rotate_double(a, b, NULL);
	else if(!ft_strncmp(line, "rrr\n", 5))
		reverse_rotate_double(a, b, NULL);
	else if(!ft_strncmp(line, "ss\n", 5))
		swap_double(a, b);
	else
		error_exit();
}

int	main(int argc, char *argv[])
{
	char *line;
	t_stack	a;
	t_stack	b;
	char	**result;

	if (argc == 1)
		error_exit();
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
	/*if (a.top == 0 || is_sorted(a))
	{
		free_split(result);
		return (1);
	}*/
	free_split(result);
	b.top = -1;
	while ((line = get_next_line(0)) != NULL)
		execute(line, &a, &b);
	if (is_sorted(a) && b.top == -1)
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}




