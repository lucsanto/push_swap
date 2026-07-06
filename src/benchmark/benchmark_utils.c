/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:11:28 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:11:30 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_two_digits(int n)
{
	if (n < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n, 2);
}

void	print_percent(double value)
{
	int	percent;

	percent = (int)(value * 10000.0 + 0.5);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	print_two_digits(percent % 100);
}

char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n sqrt(n))");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

void	print_operation_pair(char *name, int count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}
