/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:28:17 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/09 11:44:36 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_character(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
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

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar_fd(str[count], 1);
		count++;
	}
	return (count);
}
