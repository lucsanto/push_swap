/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:51:21 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:51:22 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	j = 0;
	while (j < len && big[j])
	{
		i = 0;
		while (i + j < len && big[j + i] == little[i])
			if (little[++i] == 0)
				return ((char *)(big + j));
		j++;
	}
	return (NULL);
}
