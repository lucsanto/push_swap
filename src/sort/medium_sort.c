#include "push_swap.h"

static void	move_position_to_top_a(t_data *data, int position)
{
	int	size;

	size = stack_size(data->a);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(data);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(data);
			position++;
		}
	}
}

static void	push_chunk_to_b(t_data *data, int min, int max)
{
	int	position;
	int	middle;

	middle = min + ((max - min) / 2);
	while (has_index_in_range(data->a, min, max))
	{
		position = find_range_position(data->a, min, max);
		move_position_to_top_a(data, position);
		pb(data);
		if (data->b && data->b->next && data->b->index <= middle)
			rb(data);
	}
}

static void	restore_from_b(t_data *data)
{
	while (data->b)
	{
		move_max_to_top_b(data);
		pa(data);
	}
}

void	sort_medium(t_data *data)
{
	int	size;
	int	chunk_size;
	int	min;
	int	max;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	chunk_size = integer_sqrt_ceil(size);
	min = 0;
	while (min < size)
	{
		max = min + chunk_size - 1;
		if (max >= size)
			max = size - 1;
		push_chunk_to_b(data, min, max);
		min = min + chunk_size;
	}
	restore_from_b(data);
}