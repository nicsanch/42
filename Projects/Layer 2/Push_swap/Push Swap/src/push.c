/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:52:49 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/25 11:19:35 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_node(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*new_head;

	node = ft_stack_copy_node(*a);
	new_head = (*a)-> next;
	ft_stack_delone(a, (*a)-> index);
	*a = new_head;
	ft_stack_add_front (b, node);
}

void	ft_push(t_stack **a, t_stack **b, int n)
{
	if (n == 'a')
	{
		ft_push_node(b, a);
		ft_printf("pa\n");
	}
	if (n == 'b')
	{
		ft_push_node(a, b);
		ft_printf("pb\n");
	}
}
