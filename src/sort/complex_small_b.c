/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_small_b.c                                  :+:      :+:    :+:   */
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

static void	push_b_target(t_data *data, int pos)
{
	int	rotations;

	rotations = 0;
	while (rotations++ < pos)
		rb(data);
	pa(data);
	while (--rotations > 0)
		rrb(data);
}

void	complex_small_b(t_data *data, int size, int min)
{
	int	target;
	int	pos;

	target = min + size - 1;
	while (size > 0)
	{
		pos = find_index_pos(data->b, target, size);
		push_b_target(data, pos);
		target--;
		size--;
	}
}
