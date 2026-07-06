/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:13:20 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:13:21 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_two(t_stack *stack)
{
	return (stack && stack->next);
}

void	ra(t_data *data)
{
	if (!data || !has_two(data->a))
		return ;
	rotate_stack(&data->a);
	queue_operation(data, OP_RA);
}

void	rb(t_data *data)
{
	if (!data || !has_two(data->b))
		return ;
	rotate_stack(&data->b);
	queue_operation(data, OP_RB);
}

void	rr(t_data *data)
{
	if (!data)
		return ;
	if (!has_two(data->a) && !has_two(data->b))
		return ;
	rotate_stack(&data->a);
	rotate_stack(&data->b);
	flush_operations(data);
	print_operation(data, OP_RR);
}
