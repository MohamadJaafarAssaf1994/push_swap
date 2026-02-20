/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_9.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:10:00 by mohassaf          #+#    #+#             */
/*   Updated: 2026/02/20 15:36:27 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!result[i])
		{
			free_split(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
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
