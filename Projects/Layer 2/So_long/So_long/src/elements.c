/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:20:28 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 13:47:19 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_wall_image(t_game *game)
{
	mlx_texture_t	*texture_wall;

	texture_wall = mlx_load_png("./textures/water.png");
	game->elements->wall = mlx_texture_to_image(game->mlx, texture_wall);
	mlx_resize_image(game->elements->wall, 50, 50);
	mlx_delete_texture(texture_wall);
}

void	ft_get_floor_image(t_game *game)
{
	mlx_texture_t	*texture_floor;

	texture_floor = mlx_load_png("./textures/sand.png");
	game->elements->floor = mlx_texture_to_image(game->mlx, texture_floor);
	mlx_resize_image(game->elements->floor, 50, 50);
	mlx_delete_texture(texture_floor);
}

void	ft_get_pj_image(t_game *game)
{
	mlx_texture_t	*texture_pj;

	texture_pj = mlx_load_png("./textures/pig.png");
	game->elements->pj = mlx_texture_to_image(game->mlx, texture_pj);
	mlx_delete_texture(texture_pj);
	mlx_resize_image(game->elements->pj, 40, 40);
}

void	ft_get_end_image(t_game *game)
{
	mlx_texture_t	*texture_end;

	texture_end = mlx_load_png("./textures/chest.png");
	game->elements->end = mlx_texture_to_image(game->mlx, texture_end);
	mlx_resize_image(game->elements->end, 35, 35);
	mlx_delete_texture(texture_end);
}

void	ft_get_collect_image(t_game *game)
{
	mlx_texture_t	*texture_collect;

	texture_collect = mlx_load_png("./textures/key.png");
	if (!texture_collect)
		ft_error();
	game->elements->collect = mlx_texture_to_image(game->mlx, texture_collect);
	if (mlx_resize_image(game->elements->collect, 15, 20) == false)
		ft_error();
	mlx_delete_texture(texture_collect);
}
