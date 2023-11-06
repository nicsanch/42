/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:21:30 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/02 12:49:01 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_duplicateds(t_stack *a)
{
	t_stack	*current;
	t_stack	*head;

	current = a;
	head = a -> next;
	while (current)
	{
		while (head)
		{
			if (current->value == head->value && current->index != head->index)
			{
				ft_printf("Error\n");
				exit(2);
			}
			head = head -> next;
		}
		current = current -> next;
		head = a;
	}
	return ;
}

void	ft_already_ordered(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current)
	{
		if (current->next && current->rank + 1 != (current -> next)-> rank)
			return ;
		current = current -> next;
	}
	exit (0);
}

void	ft_special_cases(t_stack **a, t_stack **b)
{
	int	argc;

	argc = ft_stack_size(*a);
	ft_already_ordered(*a);
	if (argc == 2)
		ft_order_two(a, b, 'a');
	if (argc == 3)
		ft_order_three(a, b);
	if (argc == 4)
		ft_order_four(a, b);
	if (argc == 5)
		ft_order_five(a, b);
	if (argc <= 5)
		exit (0);
}
