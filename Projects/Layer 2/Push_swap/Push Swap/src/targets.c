/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:17:55 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/19 18:14:33 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_perfect_rank(t_stack **b, int rank)
{
	t_stack	*current;
	int		max;
	int		perfect;

	max = 0;
	perfect = 0;
	current = *b;
	while (current)
	{
		if ((current -> rank < rank) && (current -> rank > perfect))
			perfect = current -> rank;
		if (current -> rank > max)
			max = current -> rank;
		current = current -> next;
	}
	current = *b;
	if (perfect == 0)
		perfect = max;
	while (current -> rank != perfect)
		current = current -> next;
	return (current);
}

t_stack	*ft_cheapest_node(t_stack **a)
{
	t_stack	*current;
	t_stack	*aux;
	int		min;

	current = *a;
	aux = *a;
	min = current -> cost;
	while (current)
	{
		if (current -> cost == 0 || current -> cost == 1)
			return (current);
		if (current -> cost < min)
			min = current -> cost;
		current = current -> next;
	}
	while (aux)
	{
		if (aux -> cost == min)
			return (aux);
		aux = aux -> next;
	}
	return (aux);
}

t_stack	*ft_perfect_rank_inc(t_stack **b, int rank)
{
	t_stack	*current;
	int		max;
	int		perfect;

	max = INT_MAX;
	perfect = INT_MAX;
	current = *b;
	while (current)
	{
		if ((current -> rank > rank) && (current -> rank < perfect))
			perfect = current -> rank;
		if (current -> rank < max)
			max = current -> rank;
		current = current -> next;
	}
	current = *b;
	if (perfect == INT_MAX)
		perfect = max;
	while (current -> rank != perfect)
		current = current -> next;
	return (current);
}

t_stack	*ft_stack_last(t_stack *lst)
{
	while (lst)
	{
		if (!lst ->next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

t_stack	*ft_min_value(t_stack *head)
{
	int		min;
	t_stack	*current;

	current = head;
	min = INT_MAX;
	while (current)
	{
		if (current -> rank == 0 && current -> value < min)
			min = current -> value;
		current = current -> next;
	}
	current = head;
	while (current)
	{
		if (current -> value == min)
		{
			return (current);
		}
		current = current -> next;
	}
	return (current);
}
