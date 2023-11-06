/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:27:06 by nicsanch          #+#    #+#             */
/*   Updated: 2023/09/26 17:04:31 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_take_arguments(int *argc, char ***argv)
{
	int	counter;
	int	y;

	counter = 0;
	while (counter < *argc)
	{
		if ((*argv)[counter] == NULL || (*argv)[counter][0] == '\0')
		{
			ft_printf("Error\n");
			exit(3);
		}
		y = -1;
		while ((*argv)[counter][++y] == ' ' )
		{
			if ((*argv)[counter][y + 1] == '\0')
			{
				ft_printf("Error\n");
				exit (4);
			}
		}
		counter++;
	}
	return ;
}

void	ft_init_stack(t_stack **stack, int n, char **contents)
{
	int		counter;
	int		split;
	int		size;
	char	**args;

	counter = 1;
	while (counter < n)
	{
		split = 0;
		args = ft_split(contents[counter], ' ');
		size = ft_bidimstrlen(args);
		while (split < size)
		{
			ft_stack_add_back(stack, ft_stack_new(args[split]));
			split++;
		}
		ft_free(args, size);
		counter++;
	}
	if (n == 1)
		exit (0);
}

void	ft_start_index(t_stack *head)
{
	int		index;
	t_stack	*current;

	current = head;
	index = 0;
	while (current)
	{
		current -> index = ++index;
		current = current -> next;
	}
}

void	ft_costs(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	ft_start_index(current);
	ft_start_index(*b);
	current = *a;
	while (current)
	{
		ft_rotations_cost(a, b);
		ft_cheapest_cost(current);
		current = current -> next;
	}
}

void	ft_init(t_stack **a, int n, char **contents)
{
	if (n == 1)
		exit (0);
	ft_init_stack(a, n, contents);
	ft_start_index(*a);
	ft_check_duplicateds(*a);
	ft_get_ranks(*a);
}
