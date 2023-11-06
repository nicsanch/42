/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:57 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/30 16:40:42 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	int	ncmd;

	ncmd = 1;
	if (argc != 5)
		return ((ft_printf("pipex needs four aguments.\n")), EXIT_FAILURE);
	ft_check_files(argv, envp);
	while (++ncmd < argc - 2)
		ft_pipe(argv, envp, ncmd);
	return (EXIT_SUCCESS);
}
