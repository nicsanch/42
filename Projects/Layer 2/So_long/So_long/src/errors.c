/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:34 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 16:52:51 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	perror("So_long: ");
	exit(EXIT_FAILURE);
}

void	ft_error_map(void)
{
	write(2, "Wrong map.\n", 12);
	exit(EXIT_FAILURE);
}

void	ft_arg_errors(int argc, char *argv)
{
	if (argc != 2)
	{
		write(2, "So_long needs one argument.\n", 29);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
	{
		write (2, "The argument given must be a map file(.ber).\n", 46);
		exit (EXIT_FAILURE);
	}
}
