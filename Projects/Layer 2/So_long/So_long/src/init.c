/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:47:34 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 16:53:07 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_game *game, int argc, char **argv)
{
	game->map = malloc(sizeof(t_map) * 10);
	if (!game->map)
		ft_error();
	ft_check_args(argc, argv, game->map);
}

void	ft_init_mlx(t_game *game)
{
	if (!game->mlx)
		ft_error();
	game->mlx = mlx_init(game->map->width * WIDTH,
			(1 + game->map->height) * HEIGHT, "So long", false);
	if (!game->mlx)
		ft_error();
}

void	ft_init_elements(t_game	*game)
{
	game->elements = malloc (sizeof(t_element) * 10);
	if (!game->elements)
		ft_error();
	ft_get_floor_image(game);
	ft_get_collect_image(game);
	ft_get_end_image(game);
	ft_get_pj_image(game);
	ft_get_wall_image(game);
}

void	ft_init_game(t_game *game, int argc, char **argv)
{
	ft_init_map(game, argc, argv);
	ft_init_mlx(game);
	ft_init_elements(game);
	ft_print_elements(game);
}
