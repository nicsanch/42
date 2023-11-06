/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:47:31 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/17 17:15:50 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*ptr;

	begin = 0;
	end = ft_strlen(s1) - 1;
	if (!*s1)
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[begin]) != 0)
		begin++;
	while (ft_strchr(set, s1[end]) != 0)
		end--;
	ptr = ft_substr(s1, begin, end - begin + 1);
	return (ptr);
}
