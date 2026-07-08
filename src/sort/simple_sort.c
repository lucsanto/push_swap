/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:37 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:15:38 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_simple_decision(int size)
{
	int	decision;

	decision = integer_sqrt_ceil(size) * 12 / 10;
	if (decision < 3)
		decision = 3;
	return (decision);
}

static void	push_simple_window(t_data *data, int *pushed, int decision)
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

void	sort_simple(t_data *data)
{
	int	decision;
	int	pushed;

	if (!data || !data->a)
		return ;
	decision = get_simple_decision(stack_size(data->a));
	pushed = 0;
	while (data->a)
		push_simple_window(data, &pushed, decision);
	restore_complex_from_b(data);
}
