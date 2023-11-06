/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:29:49 by nicsanch          #+#    #+#             */
/*   Updated: 2023/04/26 21:03:37 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char				*src1;
	char				*dest1;

	src1 = (char *) src;
	dest1 = (char *) dest;
	if (!src && !dest)
		return (dest);
	if (dest > src)
		while (n--)
			dest1[n] = src1[n];
	else
		ft_memcpy(dest1, src1, n);
	return (dest);
}
