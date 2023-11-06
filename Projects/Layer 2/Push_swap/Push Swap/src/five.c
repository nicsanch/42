/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:56 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/25 09:24:21 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_costs_inc(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	ft_start_index(current);
	ft_start_index(*b);
	current = *a;
	while (current)
	{
		ft_rotations_cost_inc(a, b);
		ft_cheapest_cost(current);
		current = current -> next;
	}
}

void	ft_rotations_cost_inc(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*chosen;
	int		size_a;
	int		size_b;

	current = *a;
	size_a = ft_stack_size(*a);
	size_b = ft_stack_size(*b);
	while (current)
	{
		ft_cost_a(current, size_a);
		chosen = ft_perfect_rank_inc(b, current -> rank);
		ft_cost_b(current, chosen, size_b);
		ft_bilateral_costs(current);
		current = current -> next;
	}
}

void	ft_order_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		rot;

	current = *a;
	size = ft_stack_size(*a);
	while (current -> rank != 1)
		current = current -> next;
	size = size - current -> index + 1;
	if (current -> index < size)
	{
		rot = current -> index - 1;
		while (rot--)
			ft_rot(a, b, 'a');
	}
	else
	{
		rot = size;
		while (rot--)
			ft_revrot(a, b, 'a');
	}
}

void	ft_move_node_f(t_stack **a, t_stack **b, t_stack *node)
{
	if (node -> flag == 0)
	{
		ft_flag_cero_f(a, b, node);
		ft_push(b, a, 'a');
		ft_costs(a, b);
	}
	if (node -> flag == 1)
	{
		ft_flag_one_f(a, b, node);
		ft_push(b, a, 'a');
		ft_costs(a, b);
	}
	if (node -> flag == 2)
	{
		ft_flag_two_f(a, b, node);
		ft_push(b, a, 'a');
		ft_costs(a, b);
	}
	if (node -> flag == 3)
	{
		ft_flag_three_f(a, b, node);
		ft_push(b, a, 'a');
		ft_costs(a, b);
	}
	return ;
}
