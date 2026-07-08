/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:54 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/08 16:35:00 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_is_reverse_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_reverse_stack(t_data *data)
{
	while (data->a)
		pb(data);
	while (data->b)
	{
		rrb(data);
		pa(data);
	}
}

void	sort_stack(t_data *data)
{
	int	size;

	if (!data || !data->a)
		return ;
	if (stack_is_sorted(data->a))
		return ;
	if (stack_is_reverse_sorted(data->a))
		return (sort_reverse_stack(data));
	size = stack_size(data->a);
	if (size <= 5)
		sort_small(data);
	else if (data->used_strategy == STRATEGY_SIMPLE)
		sort_simple(data);
	else if (data->used_strategy == STRATEGY_MEDIUM)
		sort_medium(data);
	else if (data->used_strategy == STRATEGY_COMPLEX)
		sort_complex(data);
}
