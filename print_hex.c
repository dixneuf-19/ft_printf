/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:26:34 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 06:07:58 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(size_t holder, char size)
{
	char			*s_table;
	char			*b_table;
	unsigned int	number;
	unsigned int	divide;
	int				count;

	s_table = "0123456789abcdef";
	b_table = "0123456789ABCDEF";
	number = (unsigned int)holder;
	divide = 268435456;
	count = 0;
	while (divide / 16 && number / divide == 0)
		divide = divide / 16;
	while (divide)
	{
		if (size == 'x' && write(1, s_table + (number / divide), 1) == -1)
			return (-1);
		else if (size == 'X' && write(1, b_table + (number / divide), 1) == -1)
			return (-1);
		count++;
		number = number % divide;
		divide = divide / 16;
	}
	return (count);
}
