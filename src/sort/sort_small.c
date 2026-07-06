#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->a->index > data->a->next->index)
		sa(data);
}

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	if (stack_is_sorted(data->a))
		return ;
	first = data->a->index;
	second = data->a->next->index;
	third = data->a->next->next->index;
	if (first > second && second < third && first < third)
		sa(data);
	else if (first > second && second > third)
	{
		sa(data);
		rra(data);
	}
	else if (first > second && second < third && first > third)
		ra(data);
	else if (first < second && second > third && first < third)
	{
		sa(data);
		ra(data);
	}
	else if (first < second && second > third && first > third)
		rra(data);
}

void	sort_small(t_data *data)
{
	int	size;

	size = stack_size(data->a);
	if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else
	{
		while (stack_size(data->a) > 3)
		{
			move_min_to_top(data);
			pb(data);
		}
		sort_three(data);
		while (data->b)
			pa(data);
	}
}