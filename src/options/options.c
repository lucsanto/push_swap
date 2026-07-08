/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:13:52 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:13:53 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_flag(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return (1);
	if (!ft_strncmp(arg, "--medium", 9))
		return (1);
	if (!ft_strncmp(arg, "--complex", 10))
		return (1);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (1);
	return (0);
}

static void	set_strategy(t_data *data, char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		data->strategy = STRATEGY_SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		data->strategy = STRATEGY_MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		data->strategy = STRATEGY_COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		data->strategy = STRATEGY_ADAPTIVE;
}

int	parse_options(t_data *data, int argc, char **argv, int *start)
{
	int	i;
	int	strategy_found;

	i = 1;
	strategy_found = 0;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			data->bench_enabled = 1;
		else if (is_strategy_flag(argv[i]))
		{
			if (strategy_found)
				return (0);
			set_strategy(data, argv[i]);
			strategy_found = 1;
		}
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			return (0);
		else
			break ;
		i++;
	}
	*start = i;
	return (1);
}
