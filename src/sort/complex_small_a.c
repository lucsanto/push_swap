/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_small_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:40:00 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/08 16:40:00 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_pos(t_stack *stack, int target, int limit)
{
	int	pos;

	pos = 0;
	while (stack && pos < limit)
	{
		if (stack->index == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

static void	push_a_target(t_data *data, int pos)
{
	int	rotations;

	rotations = 0;
	while (rotations++ < pos)
		ra(data);
	pb(data);
	while (--rotations > 0)
		rra(data);
}

static void	push_back_to_a(t_data *data, int total)
{
	while (total-- > 0)
		pa(data);
}

void	complex_small_a(t_data *data, int size, int min)
{
	int	target;
	int	pos;
	int	total;

	target = min;
	total = size;
	while (size > 0)
	{
		pos = find_index_pos(data->a, target, size);
		push_a_target(data, pos);
		target++;
		size--;
	}
	push_back_to_a(data, total);
}
