/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:28:27 by nicsanch          #+#    #+#             */
/*   Updated: 2023/04/29 23:31:18 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	counter;

	counter = 0;
	if (size != 0)
	{
		while (counter < size -1 && src[counter] != 0)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}	
	return (ft_strlen(src));
}
