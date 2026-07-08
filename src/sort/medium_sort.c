/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:19 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:15:21 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_medium_decision(int size)
{
	int	decision;

	decision = integer_sqrt_ceil(size) * 14 / 10;
	if (decision < 3)
		decision = 3;
	return (decision);
}

static void	push_medium_window(t_data *data, int *pushed, int decision)
{
	if (data->a->index <= *pushed)
	{
		pb(data);
		rb(data);
		(*pushed)++;
	}
	else if (data->a->index <= *pushed + decision)
	{
		pb(data);
		(*pushed)++;
	}
	else
		ra(data);
}

void	sort_medium(t_data *data)
{
	int	decision;
	int	pushed;

	if (!data || !data->a)
		return ;
	decision = get_medium_decision(stack_size(data->a));
	pushed = 0;
	while (data->a)
		push_medium_window(data, &pushed, decision);
	restore_complex_from_b(data);
}
