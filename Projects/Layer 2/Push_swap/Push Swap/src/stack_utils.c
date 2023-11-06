/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:55:57 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/25 11:18:06 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_stack_size(t_stack *head)
{
	t_stack	*current;
	int		counter;

	current = head;
	counter = 0;
	while (current)
	{
		current = current -> next;
		counter++;
	}
	return (counter);
}

t_stack	*ft_stack_copy_node(t_stack *node)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	*new = *node;
	return (new);
}

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_stack_last(*lst);
	last->next = new;
	new -> next = NULL;
}

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_stack_delone(t_stack **stack, int index)
{
	t_stack	*current;
	t_stack	*prev;

	current = *stack;
	prev = NULL;
	while (current != NULL)
	{
		if (current-> index == index)
		{
			if (prev == NULL)
				*stack = current->next;
			else
				prev -> next = current->next;
			free(current);
			current = NULL;
			return ;
		}
		prev = current;
		current = current->next;
	}
	ft_start_index(*stack);
}
