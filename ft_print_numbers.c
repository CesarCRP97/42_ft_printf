/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:30:10 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/09 11:03:37 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(int nbr, char *base, int size)
{
	long int	long_nbr;
	int			count;

	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		write(1, "-", 1);
		count++;
		long_nbr = -long_nbr;
	}
	if (long_nbr >= size)
		count += ft_putnbr_base(long_nbr / size, base, size);
	write(1, &base[long_nbr % size], 1);
	count++;
	return (count);
}

int	ft_print_number(int n)
{
	return (ft_putnbr_base(n, "0123456789", 10));
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_base((int)n, "0123456789", 10));
}

/*
 * Prints an unsigned integer in hexadecimal format to the standard output.
 * The format parameter determines whether the hexadecimal letters are uppercase or lowercase.
 * @param n The unsigned integer to be printed.
 * @param format The format character ('x' for lowercase, 'X' for uppercase).
 * @return The number of characters printed.
*/
int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_base((int)n, "0123456789abcdef", 16));
	if (format == 'X')
		return (ft_putnbr_base((int)n, "0123456789ABCDEF", 16));
}
/*
 * Prints a pointer address in hexadecimal format to the standard output.
 * If the pointer is NULL, it prints "(nil)".
 * @param ptr The pointer to be printed.
 * @return The number of characters printed.
*/
int	ft_print_pointer(void *ptr)
{
	int	count;
	unsigned long	new_ptr;
	
	count = 0;
	if (new_ptr == 0)
		count += ft_print_string("(nil)");
	else
	{
		count += ft_print_string("0x");
		count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef", 16);
	}
	return (count);
}
