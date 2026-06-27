/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:48:20 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:48:21 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;
	size_t			i;

	i = 0;
	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n && ptr_str1[i] == ptr_str2[i])
		i++;
	if (i == n)
		return (0);
	return (ptr_str1[i] - ptr_str2[i]);
}
