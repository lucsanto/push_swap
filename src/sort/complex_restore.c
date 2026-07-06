/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:27 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:14:31 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

static int	push_back_until_max(t_data *data, int len_b, int reverse)
{
	int	swap_signal;

	swap_signal = 0;
	while (data->b && data->b->index != len_b - 1)
	{
		if (data->b->index == len_b - 2)
		{
			pa(data);
			swap_signal = 1;
		}
		else if (reverse)
			rrb(data);
		else
			rb(data);
	}
	return (swap_signal);
}

void	restore_complex_from_b(t_data *data)
{
	int	len_b;
	int	position;
	int	swap_signal;

	while (data->b)
	{
		len_b = stack_size(data->b);
		position = find_index_position(data->b, len_b - 1);
		if (position > len_b / 2)
			swap_signal = push_back_until_max(data, len_b, 1);
		else
			swap_signal = push_back_until_max(data, len_b, 0);
		pa(data);
		if (swap_signal)
			sa(data);
	}
}
