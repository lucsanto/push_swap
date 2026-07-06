#include "push_swap.h"

int	integer_sqrt_ceil(int n)
{
	int	root;

	root = 1;
	while (root * root < n)
		root++;
	return (root);
}

int	has_index_in_range(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_range_position(t_stack *stack, int min, int max)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

t_stack	*find_max_index_node(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	move_max_to_top_b(t_data *data)
{
	t_stack	*max;
	int		position;
	int		size;

	max = find_max_index_node(data->b);
	position = find_node_position(data->b, max);
	size = stack_size(data->b);
	if (position <= size / 2)
	{
		while (data->b != max)
			rb(data);
	}
	else
	{
		while (data->b != max)
			rrb(data);
	}
}