/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:41:20 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/28 19:11:08 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	ft_take_arguments(&argc, &argv);
	ft_init(&a, argc, argv);
	ft_special_cases(&a, &b);
	ft_first_movs(&a, &b);
	ft_fill_b(&a, &b);
	ft_order_b(&a, &b);
	ft_fill_a(&a, &b);
	ft_free_stacks(&a);
	return (0);
}
