/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:45:09 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:45:11 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	long	nb;
	int		counter;

	nb = n;
	counter = 0;
	if (nb <= 0)
	{
		counter++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_count_digits(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
