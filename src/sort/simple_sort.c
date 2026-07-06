#include "push_swap.h"

void	sort_simple(t_data *data)
{
	if (!data || !data->a)
		return ;
	while (stack_size(data->a) > 3)
	{
		move_min_to_top(data);
		pb(data);
	}
	sort_three(data);
	while (data->b)
		pa(data);
}