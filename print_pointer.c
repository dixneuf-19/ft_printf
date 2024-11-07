/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:10 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 06:18:39 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(size_t holder)
{
	int				count;
	int				total;

	if (write(1, "0x", 2) == -1)
		return (-1);
	total = 0;
	count =  print_hex(holder / 4294967296, 'x');
	if (count == -1)
		return (-1);
	total += count;
	count = print_hex(holder, 'x');
	if (count == -1)
		return (-1);
	total += count;
	return (2 + total);
}
