/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:11:38 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:11:43 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_op(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
}

static void	print_benchmark_header(t_data *data)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(data->disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(data->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(strategy_complexity(data->used_strategy), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->ops.total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_benchmark_counts_first(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	print_bench_op("sa", data->ops.sa);
	ft_putchar_fd(' ', 2);
	print_bench_op("sb", data->ops.sb);
	ft_putchar_fd(' ', 2);
	print_bench_op("ss", data->ops.ss);
	ft_putchar_fd(' ', 2);
	print_bench_op("pa", data->ops.pa);
	ft_putchar_fd(' ', 2);
	print_bench_op("pb", data->ops.pb);
	ft_putchar_fd('\n', 2);
}

static void	print_benchmark_counts_second(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	print_bench_op("ra", data->ops.ra);
	ft_putchar_fd(' ', 2);
	print_bench_op("rb", data->ops.rb);
	ft_putchar_fd(' ', 2);
	print_bench_op("rr", data->ops.rr);
	ft_putchar_fd(' ', 2);
	print_bench_op("rra", data->ops.rra);
	ft_putchar_fd(' ', 2);
	print_bench_op("rrb", data->ops.rrb);
	ft_putchar_fd(' ', 2);
	print_bench_op("rrr", data->ops.rrr);
	ft_putchar_fd('\n', 2);
}

void	print_benchmark(t_data *data)
{
	if (!data || !data->bench_enabled)
		return ;
	print_benchmark_header(data);
	print_benchmark_counts_first(data);
	print_benchmark_counts_second(data);
}
