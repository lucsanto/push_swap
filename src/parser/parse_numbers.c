/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:06 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:14:07 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_token_to_stack(t_stack **a, char *token)
{
	int		number;
	t_stack	*node;

	if (!is_valid_number(token))
		return (0);
	if (!convert_to_int(token, &number))
		return (0);
	if (has_duplicate(*a, number))
		return (0);
	node = new_node(number);
	if (!node)
		return (0);
	add_node_back(a, node);
	return (1);
}

static int	parse_argument(t_stack **a, char *argument)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argument, ' ');
	if (!numbers || !numbers[0])
	{
		free_numbers(numbers);
		return (0);
	}
	i = 0;
	while (numbers[i])
	{
		if (!add_token_to_stack(a, numbers[i]))
		{
			free_numbers(numbers);
			return (0);
		}
		i++;
	}
	free_numbers(numbers);
	return (1);
}

int	parse_numbers(t_stack **a, int argc, char **argv, int start)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!parse_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
