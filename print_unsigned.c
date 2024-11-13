/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:59 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 05:41:20 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(size_t holder)
{
	int				count;
	int				divide;
	unsigned int	number;
	char			convert;

	count = 0;
	divide = 1000000000;
	number = (unsigned int)holder;
	while (divide / 10 && number / divide == 0)
		divide = divide / 10;
	while (divide)
	{
		convert = (number / divide) + 48;
		if (write(1, &convert, 1) == -1)
			return (-1);
		count++;
		number = number % divide;
		divide = divide / 10;
	}
	return (count);
}
