#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		start;

	init_data(&data);
	if (argc < 2)
		return (0);
	if (!parse_options(&data, argc, argv, &start))
	{
		ft_putendl_fd("Error", 2);
		free_data(&data);
		return (1);
	}
	if (start >= argc)
	{
		free_data(&data);
		return (0);
	}
	if (!parse_numbers(&data.a, argc, argv, start))
	{
		ft_putendl_fd("Error", 2);
		free_data(&data);
		return (1);
	}
	assign_indexes(data.a);
	data.disorder = compute_disorder(data.a);
	resolve_strategy(&data);
	sort_stack(&data);
	flush_operations(&data);
	print_benchmark(&data);
	free_data(&data);
	return (0);
}
