/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:59 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 21:36:20 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int uinteger)
{
	int				count;
	unsigned int	divide;
	char			convert;

	count = 0;
	divide = 1000000000;
	while (divide / 10 && uinteger / divide == 0)
		divide = divide / 10;
	while (divide)
	{
		convert = (uinteger / divide) + 48;
		if (write(1, &convert, 1) == -1)
			return (-1);
		count++;
		uinteger = uinteger % divide;
		divide = divide / 10;
	}
	return (count);
}
