/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:35:26 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 16:57:26 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_window_callback(void *param)
{
	t_game	*game;

	game = ((t_game *)param);
	mlx_delete_image(game->mlx, game->elements->collect);
	mlx_delete_image(game->mlx, game->elements->pj);
	mlx_delete_image(game->mlx, game->elements->end);
	mlx_delete_image(game->mlx, game->elements->wall);
	mlx_delete_image(game->mlx, game->elements->floor);
	mlx_close_window(game->mlx);
	ft_free(game->map->rawmap);
	free (game->elements);
	free (game->map);
}
