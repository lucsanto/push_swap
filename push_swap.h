#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct s_stack
{
	int				value;
	int				index;
	struct	s_stack	*next;
} t_stack;

int	parse_numbers(t_stack **a, int argc, char **argv);

t_stack	*new_node(int value);
void	add_node_back(t_stack **stack, t_stack *node);
int		has_duplicate(t_stack *stack, int value);
void	free_stack(t_stack **stack);

void	print_stack(t_stack *stack);//temp

#endif