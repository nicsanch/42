/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:35:02 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/26 18:00:59 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits_ptr(unsigned long number, int radix)
{
	int	digits;

	digits = 1;
	while (number / radix > 0)
	{
		digits++;
		number = number / radix;
	}
	return (digits);
}

char	*nbr_pointer(unsigned long number)
{
	char		*result;
	int			counter;
	int			sign;
	char		*base;

	base = "0123456789abcdef";
	sign = 0;
	counter = count_digits_ptr(number, 16);
	result = malloc (counter + 1);
	if (!result)
		return (0);
	result[counter] = '\0';
	while (counter > sign && counter--)
	{
		result [counter] = base [number % 16];
		number = number / 16;
	}
	return (result);
}

void	print_number_base_pointer(unsigned long number, int *pointer)
{
	char	*string;

	string = nbr_pointer(number);
	print_string(string, pointer);
	if (string != NULL)
		free (string);
	return ;
}

void	nbr_unsign(unsigned long number, int *pointer)
{
	char		*result;
	int			counter;

	counter = count_digits_ptr(number, 10);
	result = malloc (counter + 1);
	if (!result)
		return ;
	result[counter] = '\0';
	while (counter > 0 && counter--)
	{
		result[counter] = (number % 10) + '0';
		number = number / 10;
	}
	print_string(result, pointer);
	free (result);
	return ;
}

void	print_pointer(void *ptr, int *pointer)
{
	print_string("0x", pointer);
	print_number_base_pointer((unsigned long)ptr, pointer);
	return ;
}
