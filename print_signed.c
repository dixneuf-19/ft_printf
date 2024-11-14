/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:24 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 21:33:03 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int(int integer)
{
	if (integer < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		integer = -integer;
		return (1 + print_unsigned((unsigned int)integer));
	}
	return (print_unsigned((unsigned int)integer));
}

int	print_signed(int integer)
{
	if (integer == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	else if (integer == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (print_int(integer));
}
