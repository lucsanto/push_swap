#include "push_swap.h"

void	move_min_to_top(t_data *data)
{
	t_stack	*min;
	int		position;
	int		size;

	min = find_min_node(data->a);
	position = find_node_position(data->a, min);
	size = stack_size(data->a);
	if (position <= size / 2)
	{
		while (data->a != min)
			ra(data);
	}
	else
	{
		while (data->a != min)
			rra(data);
	}
}