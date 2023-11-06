/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:46:04 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/21 09:32:47 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_cost_a(t_stack *node, int size)
{
	int	index;

	index = node -> index;
	node -> ra = (index - 1);
	if (node -> index == 1)
		node -> rra = 0;
	else
		node -> rra = (size - index + 1);
}

void	ft_cost_b(t_stack *node, t_stack *b, int size)
{
	int	index;

	index = b -> index;
	node -> rb = (index - 1);
	if (index == (ft_stack_last(b))-> index)
		node -> rrb = 1;
	else
		node -> rrb = (size - index + 1);
}

void	ft_rotations_cost(t_stack **a, t_stack **b)
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
		chosen = ft_perfect_rank(b, current -> rank);
		ft_cost_b(current, chosen, size_b);
		ft_bilateral_costs(current);
		current = current -> next;
	}
}

void	ft_bilateral_costs(t_stack *node)
{
	if (node -> ra >= node -> rb)
		node -> rr = node -> rb;
	else
		node -> rr = node -> ra;
	if (node -> rra >= node -> rrb)
		node -> rrr = node -> rrb;
	else
		node -> rrr = node -> rra;
}

void	ft_cheapest_cost(t_stack *node)
{
	int	min;

	min = (node -> ra + node -> rb - node -> rr);
	node -> flag = 0;
	if ((node -> ra + node -> rrb) < min)
	{
		min = (node -> ra + node -> rrb);
		node -> flag = 1;
	}
	if ((node -> rra + node -> rrb - node -> rrr) < min)
	{
		min = (node -> rra + node -> rrb - node -> rrr);
		node -> flag = 2;
	}
	if ((node -> rra + node -> rb) < min)
	{
		min = (node -> rra + node -> rb);
		node -> flag = 3;
	}
	node -> cost = min;
}
