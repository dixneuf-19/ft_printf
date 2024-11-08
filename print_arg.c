/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:00 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 23:50:53 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char option, va_list argpass)
{
	unsigned char	character;

	if (option == 'c')
	{
		character = (unsigned char)va_arg(argpass, int);
		return (write(1, &character, 1));
	}
	if (option == 's')
		return (print_string(va_arg(argpass, size_t)));
	if (option == 'p')
		return (print_pointer(va_arg(argpass, size_t)));
	if (option == 'd' || option == 'i')
		return (print_signed(va_arg(argpass, size_t)));
	if (option == 'u')
		return (print_unsigned(va_arg(argpass, size_t)));
	if (option == 'x' || option == 'X')
		return (print_hex(va_arg(argpass, size_t), option));
	return (write(1, "%", 1));
}
