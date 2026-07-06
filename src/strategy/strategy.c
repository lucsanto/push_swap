#include "push_swap.h"

void	resolve_strategy(t_data *data)
{
	if (!data)
		return ;
	if (data->strategy != STRATEGY_ADAPTIVE)
	{
		data->used_strategy = data->strategy;
		return ;
	}
	if (data->disorder < 0.2)
		data->used_strategy = STRATEGY_SIMPLE;
	else if (data->disorder < 0.5)
		data->used_strategy = STRATEGY_MEDIUM;
	else
		data->used_strategy = STRATEGY_COMPLEX;
}
