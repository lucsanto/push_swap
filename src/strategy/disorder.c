/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:24:57 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:24:58 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	double	inversions;
	double	total_pairs;

	inversions = 0.0;
	total_pairs = 0.0;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				inversions++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (inversions / total_pairs);
}
