/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:39:41 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/25 16:57:42 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long number, int radix)
{
	int	digits;

	digits = 1;
	if (number < 0)
	{
		digits++;
		number = -number;
	}
	while (number / radix > 0)
	{
		digits++;
		number = number / radix;
	}
	return (digits);
}

char	*nbr_hex_low(long number)

{
	char		*result;
	int			counter;
	int			sign;
	char		*base;

	base = "0123456789abcdef";
	sign = 0;
	counter = count_digits(number, 16);
	result = malloc (counter + 1);
	if (!result)
		return (0);
	if (number < 0 && ++sign)
	{
		number = -number;
		result[0] = '-';
	}
	result[counter] = '\0';
	while (counter > sign && number >= 0 && counter--)
	{
		result [counter] = base [number % 16];
		number = number / 16;
	}
	return (result);
}

char	*nbr_hex_upp(long number)
{
	char		*result;
	int			counter;
	int			sign;
	char		*base;

	base = "0123456789ABCDEF";
	sign = 0;
	counter = count_digits(number, 16);
	result = malloc (counter + 1);
	if (!result)
		return (0);
	if (number < 0 && ++sign)
	{
		number = -number;
		result[0] = '-';
	}
	result[counter] = '\0';
	while (counter > sign && number >= 0 && counter--)
	{
		result [counter] = base [number % 16];
		number = number / 16;
	}
	return (result);
}

char	*nbr_tens(int number)
{
	char		*result;
	int			counter;
	int			sign;

	sign = 0;
	counter = count_digits(number, 10);
	result = malloc (counter + 1);
	if (!result)
		return (0);
	if (number < 0 && ++sign)
	{
		number = -number;
		result[0] = '-';
	}
	result[counter] = '\0';
	while (counter > sign && number >= 0 && counter--)
	{
		result[counter] = (number % 10) + '0';
		number = number / 10;
	}
	return (result);
}

void	print_number_base(long number, int *pointer, int base)
{
	char	*string;

	string = NULL;
	if (base == 10)
	{
		if (number == -2147483648)
		{
			*pointer = *pointer + write(1, "-2", 2);
			*pointer = *pointer + write(1, "147483648", 9);
		}
		else
			string = nbr_tens(number);
	}
	else if (base == 016)
		string = nbr_hex_low(number);
	else if (base == 160)
		string = nbr_hex_upp(number);
	if (string != NULL)
	{
		print_string(string, pointer);
		free (string);
	}
	return ;
}
