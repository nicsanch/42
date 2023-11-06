/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:50:02 by nicsanch          #+#    #+#             */
/*   Updated: 2023/04/29 23:40:51 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;

	counter = 0;
	while (s[counter] != '\0' && s[counter] != (char)c)
		counter++;
	if (s[counter] == (char)c)
		return ((char *)s + counter);
	return (0);
}
