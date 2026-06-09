/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:03:56 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/09 10:50:59 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

/* Function prototypes for the ft_printf implementation. */
int	ft_printf(const char *format, ...);
int	ft_print_character(char c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, char format);

/* Helper function to set the format based on the format character. */
int	ft_putnbr_base(int nbr, char *base, int size);



#endif
