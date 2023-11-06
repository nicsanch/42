/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:44:26 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/26 18:12:35 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_check_infile(char *infile)
{
	if (access(infile, F_OK | R_OK) != 0)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), infile);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_outfile(char *outfile)
{
	if (access(outfile, F_OK | W_OK) != 0)
	{
		ft_printf("pipex : %s: %s\n", strerror(errno), outfile);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_cmd(char *cmd, char **envp)
{
	char	**comand;
	char	**args;

	args = ft_get_args(cmd, envp);
	comand = ft_split(cmd, ' ');
	if (access(args[0], X_OK) != 0)
	{
		ft_printf("pipex: %s: %s\n", strerror(errno), comand[0]);
		exit(EXIT_FAILURE);
	}
	ft_free (args);
	ft_free(comand);
}

void	ft_check_files(char **argv, char **envp)
{
	int	lastcomand;
	int	i;

	i = 1;
	lastcomand = ft_array_str_len(argv) - 1;
	while (++i < lastcomand)
	{
		ft_check_cmd(argv[i], envp);
	}
	ft_check_infile(argv[1]);
}

char	*ft_path_finder(char **envp, char *cmd)
{
	int		i;
	char	**paths;
	char	*rightpath;
	char	*newpaths;

	cmd = ft_strjoin("/", cmd);
	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		newpaths = ft_strjoin(paths[i], cmd);
		free(paths[i]);
		paths[i] = ft_strdup(newpaths);
		free(newpaths);
		if (access(paths[i], X_OK) == 0)
		{
			rightpath = ft_strdup(paths[i]);
			return (ft_free(paths), free(cmd), rightpath);
		}
	}
	ft_free (paths);
	return (NULL);
}
