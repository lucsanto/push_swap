#include "push_swap.h"

static void	count_operation_part_one(t_op_count *ops, t_op op)
{
	if (op == OP_SA)
		ops->sa++;
	else if (op == OP_SB)
		ops->sb++;
	else if (op == OP_SS)
		ops->ss++;
	else if (op == OP_PA)
		ops->pa++;
	else if (op == OP_PB)
		ops->pb++;
	else if (op == OP_RA)
		ops->ra++;
}

static void	count_operation_part_two(t_op_count *ops, t_op op)
{
	if (op == OP_RB)
		ops->rb++;
	else if (op == OP_RR)
		ops->rr++;
	else if (op == OP_RRA)
		ops->rra++;
	else if (op == OP_RRB)
		ops->rrb++;
	else if (op == OP_RRR)
		ops->rrr++;
}

void	count_operation(t_data *data, t_op op)
{
	if (!data || op == OP_NONE)
		return ;
	count_operation_part_one(&data->ops, op);
	count_operation_part_two(&data->ops, op);
	data->ops.total++;
}
