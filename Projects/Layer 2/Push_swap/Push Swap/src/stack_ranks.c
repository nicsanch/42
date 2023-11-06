/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ranks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:25:36 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/21 09:29:14 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_min_rank(t_stack *head, int min, int rank)
{
	while (head)
	{
		if (head -> value == min)
		{
			head -> rank = rank;
			break ;
		}
		head = head -> next;
	}
}

void	ft_get_ranks(t_stack *head)
{
	int		rank;
	int		size;
	t_stack	*node;

	size = ft_stack_size(head);
	rank = 1;
	while (rank <= size)
	{
		node = ft_min_value(head);
		ft_min_rank(head, node -> value, rank);
		rank++;
	}
}

void	ft_min_max(t_stack *a, int *min, int *max)
{
	t_stack	*current;

	current = a;
	*min = INT_MAX;
	*max = INT_MIN;
	while (current)
	{
		if (*min > current -> rank)
			*min = current -> rank;
		if (*max < current -> rank)
			*max = current -> rank;
		current = current -> next;
	}
}
