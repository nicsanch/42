/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:12:28 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/05 21:05:07 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	cnt;
	unsigned int	result;

	result = 0;
	cnt = -1;
	while (++cnt < n && result == 0
		&& (((unsigned char *)s1)
			|| ((unsigned char *)s2)))
		result = ((unsigned char *)s1)[cnt] - ((unsigned char *)s2)[cnt];
	return (result);
}
