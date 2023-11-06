/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:37:22 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 17:33:03 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stack_new(void *content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = ft_atoi(content);
	new -> next = NULL;
	return (new);
}

int	ft_bidimstrlen(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	if (len == 0)
		len = 1;
	return (len);
}

void	ft_free_stacks(t_stack **a)
{
	int		size;

	size = (ft_stack_size(*a));
	while (size)
	{
		ft_stack_delone(a, size);
		size--;
	}
}
