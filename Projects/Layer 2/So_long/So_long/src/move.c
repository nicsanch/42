/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:54:12 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 14:07:48 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_update(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = game->map->pos[0];
	x = game->map->pos[1];
	i = -1;
	if (game->map->rawmap[y][x] == 'C')
	{
		while (1)
		{
			if ((game->elements->collect->instances[++i].x == x * WIDTH + 15)
				&& (game->elements->collect->instances[i].y == y * HEIGHT + 15))
			{
				game->elements->collect->instances[i].enabled = false;
				game->elements->collect->count--;
				break ;
			}
		}
	}
	if (game->map->rawmap[y][x] == 'E')
	{
		if (game->elements->collect->count == 0)
			ft_close_window_callback(game);
	}
}

void	ft_move(t_game *game, int y, int x)
{
	int	ydest;
	int	xdest;

	ydest = game->map->pos[0] + y;
	xdest = game->map->pos[1] + x;
	if (game->map->rawmap[ydest][xdest] != '1')
	{
		if (game->map->rawmap[ydest - y][xdest - x] != 'E')
			game->map->rawmap[ydest - y][xdest - x] = '0';
		game->elements->pj->instances->x += WIDTH * x;
		game->elements->pj->instances->y += HEIGHT * y;
		game->map->pos[0] += y;
		game->map->pos[1] += x;
		game->elements->pj->count += 1;
		game->elements->pj->instances->z = 2;
		ft_printf("Nº of movements: %i.\n", game->elements->pj->count - 1);
		ft_update(game);
	}
}

void	ft_key_response(struct mlx_key_data key_data, t_game *game)
{
	if (key_data.action == 2 || key_data.action == 1)
	{
		if (key_data.key == MLX_KEY_A)
		{
			ft_move(game, 0, -1);
		}
		if (key_data.key == MLX_KEY_W)
		{
			ft_move(game, -1, 0);
		}
		if (key_data.key == MLX_KEY_S)
		{
			ft_move(game, +1, 0);
		}
		if (key_data.key == MLX_KEY_D)
		{
			ft_move(game, 0, +1);
		}
		if (key_data.key == MLX_KEY_ESCAPE)
		{
			ft_close_window_callback(game);
		}
	}
}
