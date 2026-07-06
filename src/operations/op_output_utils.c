/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:12:33 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:12:34 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*operation_name(t_op op)
{
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	return ("rrr");
}

t_op	combined_operation(t_op pending, t_op op)
{
	if ((pending == OP_SA && op == OP_SB)
		|| (pending == OP_SB && op == OP_SA))
		return (OP_SS);
	if ((pending == OP_RA && op == OP_RB)
		|| (pending == OP_RB && op == OP_RA))
		return (OP_RR);
	if ((pending == OP_RRA && op == OP_RRB)
		|| (pending == OP_RRB && op == OP_RRA))
		return (OP_RRR);
	return (OP_NONE);
}
