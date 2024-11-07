/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:44 by mzary             #+#    #+#             */
/*   Updated: 2024/11/07 20:55:14 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(size_t holder)
{
	char	*str;
	int		i;

	if (holder == 0)
		return (write(1, "(null)", 6));
	str = (char *)holder;
	i = 0;
	while (str[i])
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
