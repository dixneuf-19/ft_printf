/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:24 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 04:07:31 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int(int number)
{
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		number = -number;
		return (1 + print_unsigned((size_t)number));
	}
	return (print_unsigned((size_t)number));
}

int	print_signed(size_t holder)
{
	int	number;

	number = (int)holder;
	if (number == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	else if (number == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (print_int(number));
}
