/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:10 by mzary             #+#    #+#             */
/*   Updated: 2024/11/14 21:43:24 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *pointer)
{
	int				count;

	if (write(1, "0x", 2) == -1)
		return (-1);
	count = print_hex((size_t)pointer, 'x');
	if (count == -1)
		return (-1);
	return (count + 2);
}
