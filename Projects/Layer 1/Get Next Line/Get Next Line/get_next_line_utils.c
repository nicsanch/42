/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:06:28 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/17 17:06:29 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

void	*ft_memcpy(void *dest, const void *src, int n)
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

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;

	if (len == 0)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

int	nl_finder(char *string)
{
	int	cnt;

	cnt = 0;
	while (string && string[cnt] != '\0')
	{
		if (string[cnt] != '\n')
			cnt++;
		else
			return (cnt + 1);
	}
	return (-1);
}

int	storage_finder(char *string)
{
	int	cnt;

	cnt = 0;
	while (string[cnt] != '\0')
	{
		if (string[cnt] == '\n')
			if (string[cnt + 1] != '\0')
				return (cnt + 1);
		cnt++;
	}
	return (-1);
}
