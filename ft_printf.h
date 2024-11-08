/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:13:35 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 23:47:54 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	check_format(const char *format);
int	print_arg(char option, va_list argpass);
int	print_string(size_t holder);
int	print_pointer(size_t holder);
int	print_signed(size_t holder);
int	print_unsigned(size_t holder);
int	print_hex(size_t holder, char size);

#endif
