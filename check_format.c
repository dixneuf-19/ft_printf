/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:11:18 by mzary             #+#    #+#             */
/*   Updated: 2024/11/06 00:11:25 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_option(char option)
{
	char	*options;

	options = "cspdiuxX%";
	while (*options)
	{
		if (option == *options)
			return (1);
		options++;
	}
	return (0);
}

int	check_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			i++;
		else if (format[i] == '%' && is_option(format[i + 1]))
			i += 2;
		else
			return (0);
	}
	return (1);
}
