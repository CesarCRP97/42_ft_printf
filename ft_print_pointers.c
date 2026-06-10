/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:45:33 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/10 12:48:58 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_direction(unsigned long ptr, char *base, int size)
{
	int	count;

	count = 0;
	if (ptr >= (unsigned long)size)
		count += ft_print_pointer_direction(ptr / size, base, size);
	write(1, &base[ptr % size], 1);
	count++;
	return (count);
}

/**
 * Prints a pointer address in hexadecimal format to the standard output.
 * If the pointer is NULL, it prints "(nil)".
 * @param ptr The pointer to be printed.
 * @return The number of characters printed.
*/
int	ft_print_pointer(void *ptr)
{
	int				count;
	unsigned long	new_ptr;

	count = 0;
	new_ptr = (unsigned long)ptr;
	if (new_ptr == 0)
		count += ft_print_string("(nil)");
	else
	{
		count += ft_print_string("0x");
		count += ft_print_pointer_direction(new_ptr, "0123456789abcdef", 16);
	}
	return (count);
}
