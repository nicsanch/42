/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:40:43 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/02 20:52:38 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	counter;
	unsigned char	*p;

	p = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (p[counter] == (unsigned char)c)
			return (p + counter);
		counter++;
	}
	return (0);
}
