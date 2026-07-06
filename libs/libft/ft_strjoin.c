/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:50:17 by lucsanto          #+#    #+#             */
/*   Updated: 2026/05/15 13:50:18 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;
	char	*aux;

	if (!s1 || !s2)
		return (NULL);
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_calloc(total_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	aux = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	return (aux);
}
