#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op_count
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_count;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef enum e_op
{
	OP_NONE,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			bench_enabled;
	t_strategy	strategy;
	t_strategy	used_strategy;
	double		disorder;
	t_op		pending_op;
	t_op_count	ops;
}	t_data;


void	init_data(t_data *data);
void	free_data(t_data *data);

int		parse_options(t_data *data, int argc, char **argv, int *start);

int		parse_numbers(t_stack **a, int argc, char **argv, int start);

t_stack	*new_node(int value);
void	add_node_back(t_stack **stack, t_stack *node);
int		has_duplicate(t_stack *stack, int value);
void	free_stack(t_stack **stack);

int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
int		find_node_position(t_stack *stack, t_stack *target);

void	assign_indexes(t_stack *stack);

void	swap_stack(t_stack **stack);
void	push_stack(t_stack **from, t_stack **to);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

char	*operation_name(t_op op);
t_op	combined_operation(t_op pending, t_op op);
void	count_operation(t_data *data, t_op op);
void	print_operation(t_data *data, t_op op);
void	queue_operation(t_data *data, t_op op);
void	flush_operations(t_data *data);

double	compute_disorder(t_stack *stack);
void	resolve_strategy(t_data *data);

void	sort_stack(t_data *data);

void	sort_three(t_data *data);
void	sort_small(t_data *data);

void	move_min_to_top(t_data *data);
void	sort_simple(t_data *data);

int		integer_sqrt_ceil(int n);
int		has_index_in_range(t_stack *stack, int min, int max);
int		find_range_position(t_stack *stack, int min, int max);
t_stack	*find_max_index_node(t_stack *stack);
void	move_max_to_top_b(t_data *data);
void	sort_medium(t_data *data);

void	restore_complex_from_b(t_data *data);
void	sort_complex(t_data *data);

void	print_benchmark(t_data *data);

#endif
