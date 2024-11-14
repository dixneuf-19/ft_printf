/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:11:47 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 22:48:34 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	argpass;
	int		written;

	total = 0;
	va_start(argpass, format);
	while (*format)
	{
		if (*format != '%' && write(1, format, 1) == -1)
			return (-1);
		else if (*format != '%' && format++)
			total++;
		else
		{
			written = print_arg(*(format + 1), argpass, &format);
			if (written == -1)
				return (-1);
			total += written;
		}
	}
	return (va_end(argpass), total);
}
