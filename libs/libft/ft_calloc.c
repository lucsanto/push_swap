/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:41:31 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:41:34 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && num > (size_t)-1 / size)
		return (NULL);
	else
		ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	if (num != 0 && size != 0)
		ft_bzero(ptr, num * size);
	return (ptr);
}
