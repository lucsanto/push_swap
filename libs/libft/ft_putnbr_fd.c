/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:49:19 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:49:20 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		i;
	char	c[11];

	nb = n;
	i = 0;
	if (nb == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
	}
	while (nb > 0)
	{
		c[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i > 0)
		write (fd, &c[--i], 1);
}
