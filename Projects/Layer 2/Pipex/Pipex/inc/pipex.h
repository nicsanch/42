/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:00 by nicsanch          #+#    #+#             */
/*   Updated: 2023/10/30 16:53:34 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

// PIPES.C //

/**
 * @brief fhis functions applies a "ncomand" that is on the argv.
 * @param argv the arguments passed to the program.
 * @param envp the environment variables.
 * @param ncmd the comand to execute.
 */
void	ft_pipe(char **argv, char **envp, int ncmd);

/**
 * @brief fhis functions read from infile and send to the pipe.
 * @param argv the arguments passed to the program.
 * @param pipe the pipe that splits the process.
 * @param envp the environment variables.
 * @param ncmd the comand to execute.
 */
void	ft_read_on_pipe(char **argv, int pipefd[2], char **envp, int ncmd);

/**
 * @brief fhis functions read from the pipe and execute a comand.
 * @param argv the arguments passed to the program.
 * @param pipe the pipe that splits the process.
 * @param envp the environment variables.
 * @param ncmd the comand to execute.
 */
void	ft_write_on_pipe(char **argv, int pipefd[2], char **envp, int ncmd);

/**
 * @brief fhis functions gets a comand and the envp to find its arguments.
 * @param envp the environment variables.
 * @param cmd the comand to execute.
 * @return the arguments needed for the comand.
 */
char	**ft_get_args(char *cmd, char **envp);

/**
 * @brief in case of error, print the error and exit.
 */
void	ft_error(void);

// CHECKS.C //

/**
 * @brief this functions finds the correct path for a comand.
 * @param envp the environment variables.
 * @param cmd the comand to check.
 * @return the path to the comand.
 */
char	*ft_path_finder(char **envp, char *cmd);

/**
 * @brief this function checks if the infile is accesible.
 * @param infile the infile.
 */
void	ft_check_infile(char *infile);

/**
 * @brief this function checks if there no outfile or is an outfile writeable.
 * @param envp the infile.
 */
void	ft_check_outfile(char *outfile);

/**
 * @brief this function checks if the comand exists and its executable.
 * @param cmd the comand.
 * @param envp the environment variables.
 */
void	ft_check_cmd(char *cmd, char **envp);

/**
 * @brief this function checks if there are the files with correct permisions.
 * @param argv the arguments for the program.
 * @param envp the environment variables.
 */
void	ft_check_files(char **argv, char **envp);

#endif