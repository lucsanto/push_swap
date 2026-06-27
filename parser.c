#include "push_swap.h"

static void	free_numbers(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static int	is_valid_number(char *token)
{
	int	i;

	if (!token || !token[0])
		return (0);
	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (!token[i])
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	convert_to_int(char *token, int *number)
{
	long	result;
	long	limit;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (token[i] == '+' || token[i] == '-')
	{
		if (token[i] == '-')
			sign = -1;
		i++;
	}
	limit = 2147483647;
	if (sign == -1)
		limit = 2147483648;
	while (token[i])
	{
		result = result * 10 + (token[i] - '0');
		if (result > limit)
			return (0);
		i++;
	}
	*number = (int)(result * sign);
	return (1);
}

static int	add_token_to_stack(t_stack **a, char *token)
{
	int		number;
	t_stack	*node;

	if (!is_valid_number(token))
		return (0);
	if (!convert_to_int(token, &number))
		return (0);
	if (has_duplicate(*a, number))
		return (0);
	node = new_node(number);
	if (!node)
		return (0);
	add_node_back(a, node);
	return (1);
}

static int	parse_argument(t_stack **a, char *argument)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argument, ' ');
	if (!numbers || !numbers[0])
	{
		free_numbers(numbers);
		return (0);
	}
	i = 0;
	while (numbers[i])
	{
		if (!add_token_to_stack(a, numbers[i]))
		{
			free_numbers(numbers);
			return (0);
		}
		i++;
	}
	free_numbers(numbers);
	return (1);
}

int	parse_numbers(t_stack **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}