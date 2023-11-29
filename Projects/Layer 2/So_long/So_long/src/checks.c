/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:57:04 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 13:41:52 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_unknow_char(char **map, char *elements)
{
	int	x;
	int	y;
	int	z;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y] != '\0')
		{
			z = -1;
			while (elements[++z])
			{
				if (elements[z] == map[x][y])
					break ;
			}
			if (elements[z] == '\0')
				ft_error_map();
		}
	}
}

void	ft_check_min_items(char **map)
{
	if ((ft_count_items(map, 'C') < 1) || (ft_count_items(map, 'E') != 1)
		|| (ft_count_items(map, 'P') != 1))
	{
		ft_error_map();
	}
}

void	ft_check_if_reachable(char **reachmap, int y, int x, t_map map)
{
	if (y < 0 || y >= map.height || x < 0 || x >= map.width)
	{
		return ;
	}
	if (reachmap[y][x] == '1' || reachmap[y][x] == '2')
	{
		return ;
	}
	reachmap[y][x] = '2';
	ft_check_if_reachable(reachmap, y - 1, x, map);
	ft_check_if_reachable(reachmap, y + 1, x, map);
	ft_check_if_reachable(reachmap, y, x - 1, map);
	ft_check_if_reachable(reachmap, y, x + 1, map);
}

void	ft_map_check(int mapfd, t_map *map)
{
	char	**rows;

	map->rawmap = ft_get_rows(mapfd);
	map->height = ft_array_str_len(map->rawmap) - 1;
	map->width = ft_strlen(map->rawmap[0]);
	ft_check_shape(map->rawmap, map->height, map->width);
	ft_check_borders(map->rawmap, map->height, map->width);
	ft_check_min_items(map->rawmap);
	ft_check_unknow_char(map->rawmap, "01CEP");
	rows = ft_copy_array_str(map->rawmap);
	ft_get_pos(map);
	ft_check_if_reachable(rows, map->pos[0], map->pos[1], *map);
	ft_check_all_reachable(rows);
	if (map->height * map->width > 965 || map->height > 26 || map->width > 51)
		ft_error_map();
	ft_free (rows);
}

void	ft_check_args(int argc, char **argv, t_map *map)
{
	int	mapfd;

	ft_arg_errors(argc, argv[1]);
	mapfd = open (argv[1], O_RDONLY);
	if (mapfd < 0)
		ft_error();
	ft_map_check(mapfd, map);
}
