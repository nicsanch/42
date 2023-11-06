/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:04 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/25 09:24:34 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_flag_cero_f(t_stack **a, t_stack **b, t_stack *node)
{
	int	rr;
	int	ra;
	int	rb;

	rr = node -> rr;
	ra = node -> ra - rr;
	rb = node -> rb - rr;
	while (rr-- > 0)
		ft_rot(a, b, 'r');
	while (ra-- > 0)
		ft_rot(b, a, 'b');
	while (rb-- > 0)
		ft_rot(b, a, 'a');
}

void	ft_flag_one_f(t_stack **a, t_stack **b, t_stack *node)
{
	int	ra;
	int	rb;

	ra = node -> ra;
	rb = node -> rrb;
	while (ra-- > 0)
		ft_rot(b, a, 'b');
	while (rb-- > 0)
		ft_revrot(b, a, 'a');
}

void	ft_flag_two_f(t_stack **a, t_stack **b, t_stack *node)
{
	int	rrr;
	int	rra;
	int	rrb;

	rrr = node -> rrr;
	rra = node -> rra - rrr;
	rrb = node -> rrb - rrr;
	while (rrr--)
		ft_revrot(b, a, 'r');
	while (rra-- > 0)
		ft_revrot(b, a, 'b');
	while (rrb-- > 0)
		ft_revrot(b, a, 'a');
}

void	ft_flag_three_f(t_stack **a, t_stack **b, t_stack *node)
{
	int	rra;
	int	rb;

	rra = node -> rra;
	rb = node -> rb;
	while (rra-- > 0)
		ft_revrot(b, a, 'b');
	while (rb-- > 0)
		ft_rot(b, a, 'a');
}
