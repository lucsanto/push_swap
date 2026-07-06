/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:29:30 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:29:31 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_numbers(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

int	is_valid_number(char *token)
{
	int	i;

	if (!token || !token[0])
		return (0);
	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (!token[i])
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

int	convert_to_int(char *token, int *number)
{
	long	result;
	long	limit;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (token[i] == '+' || token[i] == '-')
	{
		if (token[i] == '-')
			sign = -1;
		i++;
	}
	limit = 2147483647L + (sign == -1);
	while (token[i])
	{
		result = result * 10 + (token[i] - '0');
		if (result > limit)
			return (0);
		i++;
	}
	*number = (int)(result * sign);
	return (1);
}
