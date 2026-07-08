/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:13:31 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:13:32 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_two(t_stack *stack)
{
	return (stack && stack->next);
}

void	sa(t_data *data)
{
	if (!data || !has_two(data->a))
		return ;
	swap_stack(&data->a);
	queue_operation(data, OP_SA);
}

void	sb(t_data *data)
{
	if (!data || !has_two(data->b))
		return ;
	swap_stack(&data->b);
	queue_operation(data, OP_SB);
}

void	ss(t_data *data)
{
	if (!data)
		return ;
	if (!has_two(data->a) && !has_two(data->b))
		return ;
	swap_stack(&data->a);
	swap_stack(&data->b);
	flush_operations(data);
	print_operation(data, OP_SS);
}
