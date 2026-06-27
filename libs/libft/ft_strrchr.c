/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:51:33 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:51:35 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			result = (char *)str;
		str++;
	}
	if ((unsigned char)*str == (unsigned char)c)
		result = (char *)str;
	return (result);
}
