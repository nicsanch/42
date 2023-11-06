/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:38:22 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/02 12:46:33 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_order_two(t_stack **a, t_stack **b, int flag)
{
	t_stack	*second;

	second = (*a)-> next;
	if (flag == 'a' && (*a)-> rank > second -> rank)
	{
		ft_swap(a, b, flag);
		return ;
	}
	second = (*b)-> next;
	if (flag == 'b' && (*b)-> rank < second -> rank)
	{
		ft_swap(a, b, flag);
		return ;
	}
}

void	ft_order_three(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		min;
	int		max;

	ft_min_max(*a, &min, &max);
	current = *a;
	if (current -> rank == max)
		ft_rot(a, b, 'a');
	else if (current -> next -> rank == max)
		ft_revrot(a, b, 'a');
	current = *a;
	if (current -> rank != min)
		ft_swap(a, b, 'a');
}

void	ft_order_four(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		rot;

	current = *a;
	rot = 0;
	while ((current -> rank != 1) && ++rot)
		current = current -> next;
	if (rot >= 3 && ft_printf("rra\n"))
		ft_reverse_rotate(a);
	else
		while (rot-- && ft_printf("ra\n"))
			ft_rotate(a);
	ft_push(a, b, 'b');
	ft_order_three(a, b);
	ft_push(a, b, 'a');
}

void	ft_order_five(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *b;
	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	ft_order_three(a, b);
	ft_order_two(a, b, 'b');
	while (*b)
	{
		ft_costs_inc(b, a);
		node = ft_cheapest_node(b);
		ft_move_node_f(b, a, node);
	}
	ft_order_a(a, b);
}
