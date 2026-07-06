/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:02:17 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/06 15:02:18 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len_counter;

	if (!s)
		return (0);
	len_counter = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && check_case("cspdiuxX%", *(s + 1)))
		{
			s++;
			len_counter += conversions(*s, args);
		}
		else
			len_counter += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (len_counter);
}
