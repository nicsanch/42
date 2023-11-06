/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:58:22 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/19 17:18:37 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = (*stack)-> next;
	first -> next = second -> next;
	first -> index = 2;
	second -> next = first;
	second -> index = 1;
	*stack = second;
}

void	ft_swap(t_stack **a, t_stack **b, int n)
{
	if (n == 'a')
	{
		ft_swap_nodes(a);
		ft_printf("sa\n");
	}
	if (n == 'b')
	{
		ft_swap_nodes(b);
		ft_printf("sb\n");
	}
	if (n == 's')
	{
		ft_swap_nodes(a);
		ft_swap_nodes(b);
		ft_printf("ss\n");
	}
}
