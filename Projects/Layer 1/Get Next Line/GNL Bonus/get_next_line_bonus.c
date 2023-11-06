/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:54:19 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/17 19:14:21 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		counter;
	int		cnt;
	int		len;
	int		s1len;
	char	*ptr;

	cnt = -1;
	counter = -1;
	s1len = ft_strlen(s1);
	len = s1len + ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	while (++counter < s1len)
		ptr[counter] = s1[counter];
	while ((counter + ++cnt) < len - 1)
		ptr[counter + cnt] = s2[cnt];
	ptr[len - 1] = '\0';
	if (s2)
		free (s2);
	if (s1)
		free (s1);
	return (s1 = NULL, s2 = NULL, ptr);
}

char	*ft_reading(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*result;

	buffer = (char *)malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free (buffer), buffer = NULL, NULL);
	buffer[bytes_read] = '\0';
	result = NULL;
	result = ft_strjoin (result, buffer);
	while (nl_finder(result) == -1 && bytes_read == BUFFER_SIZE)
	{
		buffer = (char *)malloc (BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
	}
	return (result);
}

char	*refresh_storage(char *string)
{
	int		start;
	char	*storage;

	if (!string)
		return (NULL);
	start = storage_finder(string);
	if (start != -1)
		storage = ft_substr(string, start, ft_strlen(string) - start);
	else
		storage = NULL;
	free (string);
	string = NULL;
	return (storage);
}

char	*refresh_line(char *string)
{
	int		len;
	char	*line;

	if (string == NULL)
		return (NULL);
	len = nl_finder(string);
	if (len != -1)
		line = ft_substr(string, 0, len);
	else
		line = ft_substr(string, 0, ft_strlen(string));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*storage[256];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (storage[fd] != NULL)
	{
		line = refresh_line(storage[fd]);
		storage[fd] = refresh_storage (storage[fd]);
		if (nl_finder(line) != -1)
			return (line);
	}
	buffer = ft_reading(fd);
	if ((buffer == NULL && line == NULL)
		|| (buffer == NULL && read(fd, buffer, BUFFER_SIZE) <= -1))
	{
		if (line)
			free (line);
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	}
	line = ft_strjoin (line, refresh_line(buffer));
	storage[fd] = refresh_storage(buffer);
	return (line);
}
