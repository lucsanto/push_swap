/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:52 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:14:53 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_complex_chunk_size(int size)
{
	int	chunk;

	chunk = (integer_sqrt_ceil(size) * 6 / 5) + 2;
	if (chunk < 3)
		chunk = 3;
	return (chunk);
}

static void	init_chunk(t_chunk *chunk, int size, int step)
{
	chunk->up = (size / 2) + step;
	chunk->down = (size / 2) - step;
	chunk->last_up = size / 2;
	chunk->last_down = size / 2;
}

static int	push_to_b(t_data *data, int rotate_b, int counter)
{
	pb(data);
	if (data->b && data->b->next && rotate_b)
		rb(data);
	return (counter + 1);
}

static void	expand_chunk(t_chunk *chunk, int step)
{
	chunk->last_up = chunk->up;
	chunk->last_down = chunk->down;
	chunk->down -= step;
	chunk->up += step;
}

void	sort_complex(t_data *data)
{
	t_chunk	chunk;
	int		step;
	int		counter;
	int		size;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	step = get_complex_chunk_size(size);
	init_chunk(&chunk, size, step);
	counter = 0;
	while (data->a)
	{
		if (data->a->index >= chunk.last_up && data->a->index < chunk.up)
			counter = push_to_b(data, 0, counter);
		else if (data->a->index >= chunk.down
			&& data->a->index < chunk.last_down)
			counter = push_to_b(data, 1, counter);
		else
			ra(data);
		if (counter == step * 2)
			update_chunk(&chunk, step, &counter);
	}
	restore_complex_from_b(data);
}
