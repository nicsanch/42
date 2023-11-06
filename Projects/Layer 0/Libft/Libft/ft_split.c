/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:13 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/10 18:55:56 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_stringcounter(char const *s, char c)
{
	unsigned int	scounter;
	unsigned int	pcounter;

	scounter = 0;
	pcounter = ft_strlen(s);
	while (pcounter > 0)
	{
		pcounter--;
		if (s[pcounter] != c && (pcounter == 0 || s[pcounter - 1] == c))
			scounter++;
	}
	return (scounter);
}

char	**ft_free(char **ptr, int counter)
{
	while (counter-- > 0)
		free(ptr[counter]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	counter;
	unsigned int	globalcounter;
	unsigned int	xsize;
	char			**ptr;

	globalcounter = 0;
	counter = -1;
	ptr = malloc(sizeof(char *) * (ft_stringcounter(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (++counter < ft_stringcounter(s, c))
	{
		while (s[globalcounter] == c)
			globalcounter++;
		xsize = 0;
		while (s[globalcounter + xsize] != c && s[globalcounter + xsize])
			xsize++;
		ptr[counter] = ft_substr(s, globalcounter, xsize);
		globalcounter += xsize;
		if (!ptr[counter])
			return (ft_free(ptr, counter));
	}
	ptr[counter] = NULL;
	return (ptr);
}
