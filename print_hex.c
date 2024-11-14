/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:26:34 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 21:42:09 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(size_t hex, char size)
{
	char			*s_tab;
	char			*b_tab;
	size_t			div;
	int				count;

	s_tab = "0123456789abcdef";
	b_tab = "0123456789ABCDEF";
	div = 0x1000000000000000;
	count = 0;
	while (div / 16 && hex / div == 0)
		div = div / 16;
	while (div)
	{
		if (size == 'x' && write(1, s_tab + (hex / div), 1) == -1)
			return (-1);
		else if (size == 'X' && write(1, b_tab + (hex / div), 1) == -1)
			return (-1);
		count++;
		hex = hex % div;
		div = div / 16;
	}
	return (count);
}
