#include "push_swap.h"

static int	has_two(t_stack *stack)
{
	return (stack && stack->next);
}

void	rra(t_data *data)
{
	if (!data || !has_two(data->a))
		return ;
	reverse_rotate_stack(&data->a);
	queue_operation(data, OP_RRA);
}

void	rrb(t_data *data)
{
	if (!data || !has_two(data->b))
		return ;
	reverse_rotate_stack(&data->b);
	queue_operation(data, OP_RRB);
}

void	rrr(t_data *data)
{
	if (!data)
		return ;
	if (!has_two(data->a) && !has_two(data->b))
		return ;
	reverse_rotate_stack(&data->a);
	reverse_rotate_stack(&data->b);
	flush_operations(data);
	print_operation(data, OP_RRR);
}
