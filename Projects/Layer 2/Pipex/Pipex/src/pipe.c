/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:44:58 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/30 16:40:20 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_pipe(char **argv, char **envp, int ncmd)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	else if (pid == 0)
		ft_write_on_pipe(argv, pipefd, envp, ncmd);
	else if (pid > 0)
	{
		ft_read_on_pipe(argv, pipefd, envp, ncmd + 1);
		close (pipefd[1]);
	}
}

void	ft_read_on_pipe(char **argv, int pipefd[2], char **envp, int ncmd)
{
	int		outfilefd;
	char	**args;
	pid_t	pid;
	int		size;

	pid = fork();
	if (pid < 0)
		ft_error();
	if (pid == 0)
	{
		size = ft_array_str_len(argv);
		args = ft_get_args(argv[ncmd], envp);
		outfilefd = open (argv[size - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (outfilefd < 0)
			ft_error();
		dup2(outfilefd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		close(outfilefd);
		if (execve(args[0], args, NULL) == -1)
			ft_error();
	}
	else if (pid > 0)
		waitpid(-1, 0, 0);
}

void	ft_write_on_pipe(char **argv, int pipefd[2], char **envp, int ncmd)
{
	int		infilefd;
	char	**args;

	infilefd = open (argv[1], O_RDONLY, 0644);
	if (infilefd < 0)
		exit (EXIT_FAILURE);
	args = ft_get_args(argv[ncmd], envp);
	dup2(infilefd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close (pipefd[0]);
	close (infilefd);
	if (execve(args[0], args, NULL) == -1)
		ft_error();
}

char	**ft_get_args(char *cmd, char **envp)
{
	char	**comand;
	char	**args;
	int		i;
	char	*tmp;

	tmp = NULL;
	args = malloc(sizeof(char *) * 3);
	i = 0;
	comand = ft_split(cmd, ' ');
	args[0] = ft_path_finder(envp, comand[0]);
	args[1] = NULL;
	if (comand[1])
	{
		args[1] = "";
		while (comand[++i] && comand[i] != NULL)
		{
			tmp = ft_strjoin(args[1], comand[i]);
			args[1] = ft_strdup(tmp);
			free (tmp);
		}
	}
	ft_free (comand);
	args[2] = NULL;
	return (args);
}

void	ft_error(void)
{
	perror("pipex:");
	exit(EXIT_FAILURE);
}
