/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:02:58 by cesar             #+#    #+#             */
/*   Updated: 2026/06/09 11:20:36 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Sets the format for the printf function based on the format character.
 * @param c The format character.
 * @param args The variable argument list.
 * @return The number of characters printed.
 * Available format characters:
 * 'c' - character
 * 's' - string
 * 'p' - pointer
 * 'd' or 'i' - integer
 * 'u' - unsigned integer
 * 'x' - hexadecimal (lowercase)
 * 'X' - hexadecimal (uppercase)
 * '%' - literal percent sign
 */
static int	set_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_character(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_print_character('%'));
}

/**
 * The main function for the ft_printf implementation.
 * @param format The format string.
 * @param ... The variable arguments to be printed.
 * @return The number of characters printed, or -1 on error.
*/
int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if(format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			i++;
			count += set_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
