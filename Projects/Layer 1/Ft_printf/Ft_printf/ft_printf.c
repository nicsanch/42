/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:39:35 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/26 18:03:23 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, int *pointer)
{
	int	value;

	value = write (1, &c, 1);
	if (value < 0)
	{
		*pointer = -1;
		return ;
	}
	*pointer = *pointer + value;
	return ;
}

void	print_string(const char *string, int *pointer)
{
	int	counter;

	if (string == NULL)
	{
		*pointer = *pointer + write (1, "(null)", 6);
		return ;
	}
	counter = 0;
	while (string[counter] != '\0')
	{
		print_char(string[counter], pointer);
		if (*pointer == -1)
			return ;
		counter++;
	}
	return ;
}

void	print_variable(va_list arguments, char c, int *pointer)
{
	if (c == 'c')
		print_char(va_arg(arguments, int), pointer);
	else if (c == 's')
		print_string(va_arg(arguments, const char *), pointer);
	else if (c == 'p')
		print_pointer(va_arg(arguments, void *), pointer);
	else if (c == 'u')
		nbr_unsign(va_arg(arguments, unsigned int), pointer);
	else if (c == 'd' || c == 'i')
		print_number_base(va_arg(arguments, int), pointer, 10);
	else if (c == 'x')
		print_number_base(va_arg(arguments, unsigned int), pointer, 016);
	else if (c == 'X')
		print_number_base(va_arg(arguments, unsigned int), pointer, 160);
	else if (c == '%')
		print_char('%', pointer);
	return ;
}

int	ft_printf(char const *str, ...)
{
	va_list	arguments;
	int		counter;
	int		pos;

	if (!str)
		return (0);
	counter = 0;
	pos = 0;
	va_start(arguments, str);
	while (str[pos] != '\0')
	{
		if (str[pos] != '%')
			print_char(str[pos], &counter);
		if (str[pos] == '%' && str[pos + 1])
		{
			print_variable(arguments, str[pos + 1], &counter);
			pos++;
		}
		if (counter == -1)
			return (-1);
		pos++;
	}
	va_end(arguments);
	return (counter);
}
