/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:30:10 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/16 13:11:07 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Helper function to print a number in a specified base.
 * @param nbr The number to be printed.
 * @param base The string representing the characters of the base.
 * @param size The size of the base (e.g., 10 for decimal, 16 for hexadecimal).
 * @return The number of characters printed.
*/
static int	ft_putnbr_base(int nbr, char *base, int size)
{
	long int	long_nbr;
	int			count;
	int			write_result;

	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		write_result = write(1, "-", 1);
		if (write_result == -1)
			return (-1);
		count += write_result;
		long_nbr = -long_nbr;
	}
	if (long_nbr >= size)
	{
		write_result = ft_putnbr_base(long_nbr / size, base, size);
		if (write_result == -1)
			return (-1);
	}
	else
		write_result = write(1, &base[long_nbr % size], 1);
	if (write_result == -1)
		return (-1);
	return (count + write_result);
}

static int	ft_putnbr_unsigned_base(unsigned int nbr, char *base, int size)
{
	unsigned long int	long_nbr;
	int					count;
	int					write_result;

	long_nbr = nbr;
	count = 0;
	if (long_nbr >= (unsigned long int)size)
	{
		write_result = ft_putnbr_unsigned_base(long_nbr / size, base, size);
		if (write_result == -1)
			return (-1);
		count += write_result;
	}
	write_result = write(1, &base[long_nbr % size], 1);
	if (write_result == -1)
		return (-1);
	count += write_result;
	return (count);
}

int	ft_print_number(int n)
{
	return (ft_putnbr_base(n, "0123456789", 10));
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_unsigned_base((int)n, "0123456789", 10));
}

/**
 * Prints an unsigned integer in hexadecimal format to the standard output.
 * The format parameter determines whether the hexadecimal letters are uppercase
 * or lowercase.
 * @param n The unsigned integer to be printed.
 * @param format The format character ('x' for lowercase, 'X' for uppercase).
 * @return The number of characters printed.
*/
int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_unsigned_base((int)n, "0123456789abcdef", 16));
	if (format == 'X')
		return (ft_putnbr_unsigned_base((int)n, "0123456789ABCDEF", 16));
	return (0);
}
