/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:31:56 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/02 20:57:46 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	counter;
	int	sign;
	int	value;

	value = 0;
	sign = 1;
	counter = 0;
	while (nptr[counter] == 32 || (nptr[counter] > 8 && nptr[counter] < 14))
		counter++;
	if (nptr[counter] == '+' || nptr[counter] == '-')
		if (nptr[counter++] == '-')
			sign = -1 * sign;
	while (ft_isdigit(nptr[counter]))
		value = (value * 10) + ((int) nptr[counter++] - '0');
	return (value * sign);
}
