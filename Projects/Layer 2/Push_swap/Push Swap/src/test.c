/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:18:28 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/25 18:17:12 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_print_stack(t_stack *node)
{
	t_stack	*a;

	a = node;
	ft_printf("\nSTART of STACK\n");
	while (a)
	{
		ft_printf("\nValue:%i | Index:%i| Rank:%i | %i",
			a->value, a->index, a->rank, (a->rank) - (a->index));
		a = a->next;
	}
	ft_printf("\nEND of STACK\n");
}

void	ft_print_stack_f(t_stack *node)
{
	t_stack	*a;

	a = node;
	ft_printf("\nSTART of STACK\n");
	while (a)
	{
		ft_printf("\nCurrent:%p|Value:%i|Next:%p|Index:%i|Rank:%i|Cost = %i|\n",
			&*a, a->value, a->next, a->index, a->rank, a->cost);
		ft_printf("ra=%i rra=%i rb=%i rrb=%i rr=%i rrr=%i flag=%i\n",
			a->ra, a->rra, a->rb, a->rrb, a->rr, a->rrr, a->flag);
		a = a->next;
	}
	ft_printf("\nEND of STACK\n");
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
