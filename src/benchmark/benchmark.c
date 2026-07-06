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
