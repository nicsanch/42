/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:40:04 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 13:44:55 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_shape(char **map, unsigned int height, unsigned int width)
{
	unsigned int	y;

	y = 0;
	if (!map || !*map)
		ft_error_map();
	while (y++ < height)
		if (ft_strlen(map[y]) != width)
			ft_error_map();
}

void	ft_check_borders(char **map, int height, int width)
{
	int	x;

	x = -1;
	while (map[++x] != NULL)
	{
		if (map[x][0] != '1' || map[x][width - 1] != '1')
			ft_error_map();
	}
	x = -1;
	while (map[0][++x] != '\0')
	{
		if (map[0][x] != '1' || map[height][x] != '1')
			ft_error_map();
	}
}

void	ft_check_all_reachable(char **map)
{
	if (ft_count_items(map, 'E') + ft_count_items(map, 'C') != 0)
	{
		ft_error_map();
	}
}

void	ft_check_empty_lines(char *map, int split_len)
{
	int	counter;
	int	nl;

	nl = 0;
	counter = 0;
	while (map[counter] != '\0')
	{
		if (map[counter] == '\n')
			nl++;
		counter++;
	}
	if (nl != split_len)
		ft_error_map();
}
