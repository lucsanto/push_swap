#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !to || !*from)
		return ;
	node = *from;
	*from = node->next;
	node->next = *to;
	*to = node;
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	previous = NULL;
	last = *stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack;
	*stack = last;
}