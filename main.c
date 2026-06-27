#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_numbers(&a, argc, argv))
	{
		ft_putendl_fd("Error", 2);
		free_stack(&a);
		return (1);
	}
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
