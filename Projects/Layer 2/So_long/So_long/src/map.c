/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:53:33 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 16:51:43 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_cell(t_game *game, int y, int x)
{
	if (game->map->rawmap[y][x] != '1')
	{
		mlx_image_to_window(game->mlx, game->elements->floor,
			WIDTH * x, y * HEIGHT);
		mlx_set_instance_depth(&game->elements->floor
			->instances[game->elements->floor->count - 1], -2);
		if (game->map->rawmap[y][x] == 'C')
			mlx_image_to_window(game->mlx, game->elements->collect,
				x * WIDTH + 15, y * HEIGHT + 15);
		if (game->map->rawmap[y][x] == 'E')
		{
			mlx_image_to_window(game->mlx, game->elements->end,
				x * WIDTH + 8, y * HEIGHT + 10);
			mlx_set_instance_depth(&game->elements->end
				->instances[0], -1);
		}
		if (game->map->rawmap[y][x] == 'P')
			mlx_image_to_window(game->mlx, game->elements->pj,
				x * WIDTH + 5, y * HEIGHT + 5);
	}
	else
		mlx_image_to_window(game->mlx, game->elements->wall,
			x * WIDTH, y * HEIGHT);
}

void	ft_print_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->rawmap[y])
	{
		x = 0;
		while (game->map->rawmap[y][x] != '\0')
		{
			ft_print_cell(game, y, x);
			x++;
		}
		y++;
	}
}
