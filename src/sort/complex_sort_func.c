/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:21:49 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:21:51 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_chunk(t_chunk *chunk, int step, int *counter)
{
	chunk->last_up = chunk->up;
	chunk->last_down = chunk->down;
	chunk->down -= step;
	chunk->up += step;
	*counter = 0;
}
