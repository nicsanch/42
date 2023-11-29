/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:55:37 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:55 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)

{
	unsigned int	counter;
	unsigned int	lilsize;

	lilsize = ft_strlen(little);
	counter = 0;
	if (!*big && *little)
		return (0);
	while (counter <= len - lilsize && lilsize <= len)
	{
		if (ft_strncmp(big + counter, little, lilsize) == 0)
			return ((char *)big + counter);
		else
			counter++;
	}
	return (0);
}
