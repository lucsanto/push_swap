/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:50:00 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/08 18:10:00 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_b(t_data *data, int size, int min)
{
	if (size <= 0)
		return (1);
	if (size <= 5)
	{
		complex_small_b(data, size, min);
		return (1);
	}
	return (0);
}

static int	partition_b(t_data *data, int size, int pivot)
{
	int	count;
	int	rotations;

	count = 0;
	rotations = 0;
	while (count < size)
	{
		if (data->b->index >= pivot)
			pa(data);
		else
		{
			rb(data);
			rotations++;
		}
		count++;
	}
	return (rotations);
}

static void	restore_b_rotation(t_data *data, int rotations, int lower)
{
	while (stack_size(data->b) > lower && rotations > 0)
	{
		rrb(data);
		rotations--;
	}
}

void	quick_sort_b(t_data *data, int size, int min)
{
	int	pivot;
	int	lower;
	int	rotations;

	if (handle_small_b(data, size, min))
		return ;
	pivot = min + size / 2;
	lower = size / 2;
	rotations = partition_b(data, size, pivot);
	restore_b_rotation(data, rotations, lower);
	quick_sort_a(data, size - lower, pivot);
	quick_sort_b(data, lower, min);
}
