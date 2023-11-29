/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:52:49 by nicsanch          #+#    #+#             */
/*   Updated: 2023/04/24 16:43:56 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	int		counter;

	counter = 0;
	dest1 = (char *) dest;
	src1 = (char *) src;
	if (!dest && !src)
		return (0);
	while (n-- > 0)
	{
		dest1[counter] = src1[counter];
		counter++;
	}
	return (dest);
}
