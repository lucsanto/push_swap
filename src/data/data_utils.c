/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:12:02 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:12:04 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	if (!data)
		return ;
	data->a = NULL;
	data->b = NULL;
	data->bench_enabled = 0;
	data->strategy = STRATEGY_ADAPTIVE;
	data->used_strategy = STRATEGY_ADAPTIVE;
	data->disorder = 0.0;
	data->pending_op = OP_NONE;
	ft_bzero(&data->ops, sizeof(t_op_count));
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
}
