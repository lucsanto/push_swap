/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:49:48 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:49:49 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
		{
			if ((unsigned char)*str == (unsigned char)c)
				return ((char *)str);
			str++;
		}
	if ((unsigned char)*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
