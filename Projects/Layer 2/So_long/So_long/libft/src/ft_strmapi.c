/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:59:02 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/09 19:21:53 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*returned;

	returned = malloc(ft_strlen(s) + 1);
	if (!returned)
		return (NULL);
	counter = 0;
	returned[ft_strlen(s)] = '\0';
	while (s[counter] != '\0')
	{
		returned[counter] = f(counter, s[counter]);
		counter++;
	}
	return (returned);
}
