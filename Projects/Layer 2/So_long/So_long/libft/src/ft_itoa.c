/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:36:50 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/26 16:19:00 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnneg(int n, char *ptr)
{
	if (n == -2147483648)
	{
		ptr[10] = '8';
		n = -214748364;
	}
	ptr[0] = '-';
	n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		container;
	char	*ptr;

	container = n;
	digits = 1;
	if (n < 0)
		digits++;
	while (container / 10 != 0 && digits++)
		container = container / 10;
	ptr = malloc(digits + 1);
	if (!ptr)
		return (NULL);
	ptr[--digits + 1] = '\0';
	if (n == -2147483648)
		digits--;
	if (n < 0)
		n = ft_isnneg(n, ptr);
	while (n > 9 && digits--)
	{
		ptr[digits + 1] = n % 10 + '0';
		n = n / 10;
	}
	ptr[digits] = n % 10 + '0';
	return (ptr);
}
