/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:54 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:15:55 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *data)
{
	int	size;

	if (!data || !data->a)
		return ;
	if (stack_is_sorted(data->a))
		return ;
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
