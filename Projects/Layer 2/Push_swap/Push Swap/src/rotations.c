/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:53:48 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 13:12:25 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	last = ft_stack_copy_node(*stack);
	last -> index = 0;
	ft_stack_delone(stack, 1);
	*stack = last -> next;
	ft_stack_add_back(stack, last);
	ft_start_index(*stack);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*new;

	new = *stack;
	last = ft_stack_last(*stack);
	last -> next = *stack;
	*stack = last;
	while (new -> next != last)
		new = new -> next;
	new -> next = NULL;
}

void	ft_revrot(t_stack **a, t_stack **b, int n)
{
	if (n == 'a')
	{
		ft_reverse_rotate(a);
		ft_printf("rra\n");
	}
	if (n == 'b')
	{
		ft_reverse_rotate(b);
		ft_printf("rrb\n");
	}
	if (n == 'r')
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
		ft_printf("rrr\n");
	}
}

void	ft_rot(t_stack **a, t_stack **b, int n)
{
	if (n == 'a')
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
	if (n == 'b')
	{
		ft_rotate(b);
		ft_printf("rb\n");
	}
	if (n == 'r')
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
}
