/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:24:20 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 14:24:13 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_two(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(a, 'a', NULL);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(b, 'b', NULL);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_double(a, b, NULL);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_double(a, b, NULL);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_double(a, b);
	else
	{
		free(line);
		stack_free(a);
		stack_free(b);
		get_next_line(-1);
		error_exit();
	}
}

static void	execute_one(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(a, 'a', NULL);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b, 'b', NULL);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(a, 'a', NULL);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(b, 'b', NULL);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_double(a, b, 'a', NULL);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_double(b, a, 'b', NULL);
	else
		execute_two(line, a, b);
}

static void	process_operations(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_one(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

static void	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**result;

	if (argc == 1)
		error_exit();
	if (argc == 2)
		result = ft_split(argv[1], ' ');
	else
		result = get_args(argc, argv);
	stack_init(a);
	stack_init(b);
	get_and_validate_stack(a, result, b);
	free_split(result);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stacks(argc, argv, &a, &b);
	process_operations(&a, &b);
	if (is_sorted(a) && b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_free(&a);
	stack_free(&b);
	return (0);
}
