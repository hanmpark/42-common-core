/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:33:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 22:25:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	firstCommand(char **argv, char **envp, int *pipe)
{
	int		fileIn;
	char	**cmd;

	close(pipe[0]);
	fileIn = open(argv[1], O_RDONLY);
	if (fileIn < 0)
		ft_error(ERR);
	cmd = ft_split(argv[2], ' ');
	dup2(fileIn, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	close(fileIn);
	exec_cmd(cmd, envp);
}

static void	secondCommand(char **argv, char **envp, int *pipe)
{
	int		fileOut;
	char	**cmd;

	close(pipe[1]);
	fileOut = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fileOut < 0)
		ft_error(ERR);
	cmd = ft_split(argv[3], ' ');
	dup2(fileOut, STDOUT_FILENO);
	dup2(pipe[0], STDIN_FILENO);
	close(fileOut);
	close(pipe[0]);
	exec_cmd(cmd, envp);
}

static void	pipex(char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_FORK);
	else if (pid == 0)
		firstCommand(argv, envp, fd);
	waitpid(pid, NULL, 0);
	secondCommand(argv, envp, fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
		ft_error(ERR_ARGS);
	pipex(argv, envp);
	return (0);
}
