/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:52 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/08 18:10:00 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_a(t_data *data, int size, int min)
{
	if (size <= 1)
		return (1);
	if (size <= 5)
	{
		complex_small_a(data, size, min);
		return (1);
	}
	return (0);
}

static int	partition_a(t_data *data, int size, int pivot)
{
	int	count;
	int	rotations;

	count = 0;
	rotations = 0;
	while (count < size)
	{
		if (data->a->index < pivot)
			pb(data);
		else
		{
			ra(data);
			rotations++;
		}
		count++;
	}
	return (rotations);
}

static void	restore_a_rotation(t_data *data, int rotations, int upper)
{
	while (stack_size(data->a) > upper && rotations > 0)
	{
		rra(data);
		rotations--;
	}
}

void	quick_sort_a(t_data *data, int size, int min)
{
	int	pivot;
	int	upper;
	int	rotations;

	if (handle_small_a(data, size, min))
		return ;
	pivot = min + size / 2;
	upper = size - size / 2;
	rotations = partition_a(data, size, pivot);
	restore_a_rotation(data, rotations, upper);
	quick_sort_a(data, upper, pivot);
	quick_sort_b(data, size / 2, min);
}

void	sort_complex(t_data *data)
{
	int	size;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	if (size <= 100)
	{
		sort_medium(data);
		return ;
	}
	quick_sort_a(data, size, 0);
}
