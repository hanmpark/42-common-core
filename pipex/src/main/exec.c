/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:18:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 14:44:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errors.h"

/* Executes the command */
static void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (execve(cmd_args[0], cmd_args, envp) == -1)
		ft_freestr_array(cmd_args);
	cmd_args = define_cmdargs(cmd, define_path(envp));
	if (execve(cmd_args[0], cmd_args, envp) == -1)
	{
		ft_freestr_array(cmd_args);
		ft_error(ERR_EXEC);
	}
}

/* Execute the sent command in the child process */
static void	child_process(int fileout, char *cmd, char **envp, int *pfd)
{
	close(pfd[READ_END]);
	dup2(pfd[WRITE_END], STDOUT_FILENO);
	close(pfd[WRITE_END]);
	close(fileout);
	exec_cmd(cmd, envp);
}

/* Creates a new child process to execute the sent command in it */
static void	write_end(int fileout, char *cmd, char **envp)
{
	int	pid;
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		close(fileout);
		ft_error(ERR_PIPE);
	}
	pid = fork();
	if (pid == -1)
	{
		close(fileout);
		close(pfd[READ_END]);
		close(pfd[WRITE_END]);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
		child_process(fileout, cmd, envp, pfd);
	close(pfd[WRITE_END]);
	dup2(pfd[READ_END], STDIN_FILENO);
	close(pfd[READ_END]);
}

/* Creates a new child process to execute the second command */
static void	read_end(int fileout, char *cmd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		close(fileout);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
	{
		dup2(fileout, STDOUT_FILENO);
		close(fileout);
		exec_cmd(cmd, envp);
	}
	waitpid(pid, NULL, 0);
}

void	run_cmd(char **argv, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error(ERR_OPEN);
	define_stdin(argv, fileout);
	write_end(fileout, argv[2], envp);
	read_end(fileout, argv[3], envp);
}
