/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:06:19 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 13:51:15 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		ft_error();
	ft_init_game(game, argc, argv);
	mlx_key_hook(game->mlx, (void *)&(ft_key_response), game);
	mlx_close_hook(game->mlx, ft_close_window_callback, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
