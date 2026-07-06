#include "push_swap.h"

static void	print_two_digits(int n)
{
	if (n < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n, 2);
}

static void	print_percent(double value)
{
	int	percent;

	percent = (int)(value * 10000.0 + 0.5);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	print_two_digits(percent % 100);
}

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n sqrt(n))");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

static void	print_operation_pair(char *name, int count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_benchmark_header(t_data *data)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(data->disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] requested: ", 2);
	ft_putendl_fd(strategy_name(data->strategy), 2);
	ft_putstr_fd("[bench] used: ", 2);
	ft_putstr_fd(strategy_name(data->used_strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(strategy_complexity(data->used_strategy), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->ops.total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_benchmark_counts(t_data *data)
{
	print_operation_pair("sa", data->ops.sa);
	print_operation_pair("sb", data->ops.sb);
	print_operation_pair("ss", data->ops.ss);
	print_operation_pair("pa", data->ops.pa);
	print_operation_pair("pb", data->ops.pb);
	print_operation_pair("ra", data->ops.ra);
	print_operation_pair("rb", data->ops.rb);
	print_operation_pair("rr", data->ops.rr);
	print_operation_pair("rra", data->ops.rra);
	print_operation_pair("rrb", data->ops.rrb);
	print_operation_pair("rrr", data->ops.rrr);
}

void	print_benchmark(t_data *data)
{
	if (!data || !data->bench_enabled)
		return ;
	print_benchmark_header(data);
	print_benchmark_counts(data);
}
