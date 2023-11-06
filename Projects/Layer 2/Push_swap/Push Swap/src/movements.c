/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:58:26 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 12:57:33 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_first_movs(t_stack **a, t_stack **b)
{
	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	ft_start_index(*b);
	ft_costs(a, b);
}

void	ft_fill_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	while (*a)
	{
		ft_costs(a, b);
		node = ft_cheapest_node(a);
		ft_move_node(a, b, node);
	}
}

void	ft_fill_a(t_stack **a, t_stack **b)
{
	while (*b)
		ft_push(a, b, 'a');
}

void	ft_order_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		rot;

	current = *b;
	size = ft_stack_size(*b);
	while (current -> rank != size)
		current = current -> next;
	size = size - current -> index + 1;
	if (current -> index < size)
	{
		rot = current -> index - 1;
		while (rot--)
			ft_rot(a, b, 'b');
	}
	else
	{
		rot = size;
		while (rot--)
			ft_revrot(a, b, 'b');
	}
}

void	ft_move_node(t_stack **a, t_stack **b, t_stack *node)
{
	if (node -> flag == 0)
	{
		ft_flag_cero(a, b, node);
		ft_push(a, b, 'b');
		ft_costs(a, b);
	}
	if (node -> flag == 1)
	{
		ft_flag_one(a, b, node);
		ft_push(a, b, 'b');
		ft_costs(a, b);
	}
	if (node -> flag == 2)
	{
		ft_flag_two(a, b, node);
		ft_push(a, b, 'b');
		ft_costs(a, b);
	}
	if (node -> flag == 3)
	{
		ft_flag_three(a, b, node);
		ft_push(a, b, 'b');
		ft_costs(a, b);
	}
	return ;
}
