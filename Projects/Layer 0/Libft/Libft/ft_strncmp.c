/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:44:49 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/07 19:04:14 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;
	unsigned int	result;

	result = 0;
	counter = -1;
	while (++counter < n && result == 0 && (s1[counter] || s2[counter]))
		result = (unsigned char)s1[counter] - (unsigned char)s2[counter];
	return (result);
}
