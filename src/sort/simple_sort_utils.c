/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:29 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:15:30 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_data *data)
{
	t_stack	*min;
	int		position;
	int		size;

	min = find_min_node(data->a);
	position = find_node_position(data->a, min);
	size = stack_size(data->a);
	if (position <= size / 2)
	{
		while (data->a != min)
			ra(data);
	}
	else
	{
		while (data->a != min)
			rra(data);
	}
}
