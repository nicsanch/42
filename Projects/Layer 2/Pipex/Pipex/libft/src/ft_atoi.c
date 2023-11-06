/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:31:56 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 13:03:17 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	int				counter;
	int				sign;
	long long int	value;

	value = 0;
	sign = 1;
	counter = 0;
	while (nptr[counter] == 32 || (nptr[counter] > 8 && nptr[counter] < 14))
		counter++;
	if (nptr[counter] == '+' || nptr[counter] == '-')
		if (nptr[counter++] == '-')
			sign = -1 * sign;
	while (ft_isdigit(nptr[counter]))
		value = (value * 10) + ((long int) nptr[counter++] - '0');
	if ((nptr[counter] != ' ' && nptr[counter] != '\0')
		|| (value > INT_MAX || value < INT_MIN)
		|| (value == 0 && nptr[counter - 1] != '0'))
	{
		ft_printf("Error\n");
		exit (1);
	}
	return (value * sign);
}
