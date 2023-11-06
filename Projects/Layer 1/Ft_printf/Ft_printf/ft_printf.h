/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:43:36 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/26 18:13:40 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		count_digits(long number, int radix);
int		count_digits_ptr(unsigned long number, int radix);
char	*nbr_hex_low(long number);
char	*nbr_hex_upp(long number);
char	*nbr_tens(int number);
void	print_char(int c, int *pointer);
void	print_string(const char *string, int *pointer);
void	print_number_base(long number, int *pointer, int base);
void	print_pointer(void *ptr, int *pointer);
void	print_variable(va_list arguments, char c, int *pointer);
int		ft_printf(char const *str, ...);
char	*nbr_pointer(unsigned long number);
void	print_number_base_pointer(unsigned long number, int *pointer);
void	nbr_unsign(unsigned long number, int *pointer);

#endif