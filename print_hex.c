/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:26:34 by mzary             #+#    #+#             */
/*   Updated: 2024/11/07 23:15:53 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(size_t holder, char size)
{
	char			*s_table;
	char			*b_table;
	size_t			divide;
	int				count;

	s_table = "0123456789abcdef";
	b_table = "0123456789ABCDEF";
	divide = 0x1000000000000000;
	count = 0;
	while (divide / 16 && holder / divide == 0)
		divide = divide / 16;
	while (divide)
	{
		if (size == 'x' && write(1, s_table + (holder / divide), 1) == -1)
			return (-1);
		else if (size == 'X' && write(1, b_table + (holder / divide), 1) == -1)
			return (-1);
		count++;
		holder = holder % divide;
		divide = divide / 16;
	}
	return (count);
}
