/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:00 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 04:07:09 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char option, size_t holder)
{
	unsigned char	character;

	if (option == 'c')
	{
		character = (unsigned char)holder;
		return (write(1, &character, 1));
	}
	if (option == 's')
		return (print_string(holder));
	if (option == 'p')
		return (print_pointer(holder));
	if (option == 'd' || option == 'i')
		return (print_signed(holder));
	if (option == 'u')
		return (print_unsigned(holder));
	if (option == 'x' || option == 'X')
		return (print_hex(holder, option));
	return (write(1, "%", 1));
}
