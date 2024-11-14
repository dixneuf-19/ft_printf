/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:00 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 22:35:19 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char option, va_list argpass, const char **p_format)
{
	unsigned char	character;

	if (option == 'c')
	{
		character = (unsigned char)va_arg(argpass, int);
		return (*p_format += 2, write(1, &character, 1));
	}
	if (option == 's')
		return (*p_format += 2, print_string(va_arg(argpass, char *)));
	if (option == 'p')
		return (*p_format += 2, print_pointer(va_arg(argpass, void *)));
	if (option == 'd' || option == 'i')
		return (*p_format += 2, print_signed(va_arg(argpass, int)));
	if (option == 'u')
		return (*p_format += 2, print_unsigned(va_arg(argpass, unsigned int)));
	if (option == 'x' || option == 'X')
		return (*p_format += 2, print_hex(va_arg(argpass, size_t), option));
	if (option == '%')
		return (*p_format += 2, write(1, "%", 1));
	return (*p_format += 1, 0);
}
