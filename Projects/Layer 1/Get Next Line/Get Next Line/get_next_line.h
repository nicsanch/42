/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:23:33 by nicsanch          #+#    #+#             */
/*   Updated: 2023/07/17 20:05:35 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_substr(char *s, int start, int len);
int		nl_finder(char *string);
int		storage_finder(char *string);
char	*ft_strjoin(char *s1, char *s2);
char	*refresh_storage(char *string);
char	*ft_reading(int fd);
char	*get_next_line(int fd);
char	*refresh_line(char *string);

#endif
