#include "push_swap.h"

void	pa(t_data *data)
{
	if (!data || !data->b)
		return ;
	push_stack(&data->b, &data->a);
	flush_operations(data);
	print_operation(data, OP_PA);
}

void	pb(t_data *data)
{
	if (!data || !data->a)
		return ;
	push_stack(&data->a, &data->b);
	flush_operations(data);
	print_operation(data, OP_PB);
}
