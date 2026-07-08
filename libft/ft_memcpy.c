/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:48:28 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:48:29 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_ptr;
	const unsigned char		*src_ptr;

	dest_ptr = dest;
	src_ptr = (unsigned char *)src;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}
