/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:18:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 17:57:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/pipex.h"
#include "main/errors.h"

/* Execute the sent command in the child process */
static void	exec_cmd(int fileout, char *cmd, char **envp, int *pfd)
{
	char	**cmd_args;

	close(pfd[READ_END]);
	cmd_args = define_cmdargs(cmd, define_path(envp));
	dup2(pfd[WRITE_END], STDOUT_FILENO);
	close(pfd[WRITE_END]);
	close(fileout);
	execve(cmd_args[0], cmd_args, envp);
}

/* Creates a new child process to execute the sent command in it */
static void	write_end(int fileout, char *cmd, char **envp)
{
	int	pid;
	int	pfd[2];

	if (pipe(pfd) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
	{
		close(pfd[READ_END]);
		close(pfd[WRITE_END]);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
		exec_cmd(fileout, cmd, envp, pfd);
	close(pfd[WRITE_END]);
	dup2(pfd[READ_END], STDIN_FILENO);
	close(pfd[READ_END]);
}

/* Creates a new child process to execute the second command */
static void	read_end(int fileout, char *cmd, char **envp)
{
	char	**cmd_args;
	int		pid;

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
		cmd_args = define_cmdargs(cmd, define_path(envp));
		execve(cmd_args[0], cmd_args, envp);
	}
	waitpid(pid, NULL, 0);
}

static void	set_stdin(char **argv, int fileout)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		close(fileout);
		ft_error(ERR_OPEN);
	}
	dup2(filein, STDIN_FILENO);
	close(filein);
}

void	run_cmd(char **argv, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
		ft_error(ERR_OPEN);
	set_stdin(argv, fileout);
	write_end(fileout, argv[2], envp);
	read_end(fileout, argv[3], envp);
}
