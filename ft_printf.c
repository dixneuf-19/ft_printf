/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:11:47 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 00:40:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	argpass;
	int		written;

	if (check_format(format) == 0)
		return (-1);
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
			written = print_arg(*((char *)format + 1), va_arg(argpass, size_t));
			if (written == -1)
				return (-1);
			total += written;
			format += 2;
		}
	}
	return (va_end(argpass), total);
}
