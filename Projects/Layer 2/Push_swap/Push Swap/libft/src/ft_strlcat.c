/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:58 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/17 16:10:34 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	counter;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	counter = 0;
	if (dstlen >= size)
		return (srclen + size);
	while (counter < size - dstlen - 1 && src[counter])
	{
		dst[dstlen + counter] = src[counter];
		counter++;
	}
	dst[dstlen + counter] = '\0';
	return (dstlen + srclen);
}
