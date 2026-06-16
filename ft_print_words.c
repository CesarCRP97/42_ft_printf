/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:28:17 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/16 12:58:02 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_character(char c)
{
	int	write_result;

	write_result = write(1, &c, 1);
	return (write_result);
}

/**
 * Prints a string to the standard output and returns the number of characters 
 * printed.
 * If the input string is NULL, it prints "(null)" and returns 6.
 * @param str The string to be printed.
 * @return The number of characters printed.
*/
int	ft_print_string(char *str)
{
	int	count;
	int	write_result;

	if (!str)
	{
		write_result = ft_print_string("(null)");
		return (write_result);
	}
	count = 0;
	while (str[count] != '\0')
	{
		write_result = ft_print_character(str[count]);
		if (write_result == -1)
			return (-1);
		count += write_result;
	}
	return (count);
}
