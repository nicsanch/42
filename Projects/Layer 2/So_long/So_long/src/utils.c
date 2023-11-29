/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:56:46 by nicsanch          #+#    #+#             */
/*   Updated: 2023/11/28 17:00:51 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_pos(t_map *map)
{
	int		x;
	int		y;
	char	**temp;

	temp = map->rawmap;
	y = -1;
	while (temp[++y])
	{
		x = -1;
		while (temp[y][++x] != '\0')
		{
			if (temp[y][x] == 'P')
			{
				map->pos[0] = y;
				map->pos[1] = x;
				return ;
			}
		}
	}
}

int	ft_count_items(char **map, int flag)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y] != '\0')
		{
			if (map[x][y] == flag)
				count++;
		}
	}
	return (count);
}

char	**ft_get_rows(int mapfd)
{
	char	*map;
	char	*buffer;
	char	*temp;
	char	**rows;
	int		bytes_read;

	buffer = malloc (BUFSIZ + 1);
	temp = malloc (BUFSIZ + 1);
	bytes_read = read(mapfd, buffer, BUFSIZ);
	if (bytes_read < 1)
		ft_error_map();
	while (bytes_read > 0)
	{
		map = ft_strjoin(temp, buffer);
		free (temp);
		free (buffer);
		bytes_read = read(mapfd, buffer, BUFSIZ);
	}
	rows = ft_split(map, '\n');
	ft_check_empty_lines(map, ft_array_str_len(rows) - 1);
	free (map);
	if (rows == NULL)
		ft_error_map();
	return (rows);
}

char	**ft_copy_array_str(char **array)
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(ft_array_str_len(array) * sizeof(char *) + 1);
	while (array[i])
	{
		result[i] = ft_substr(array[i], 0, ft_strlen(array[1]));
		i++;
	}
	result[i] = NULL;
	return (result);
}
