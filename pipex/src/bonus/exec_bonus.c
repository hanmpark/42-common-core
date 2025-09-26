/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 08:27:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "errors_bonus.h"

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
	close(fileout);
	close(pfd[READ_END]);
	dup2(pfd[WRITE_END], STDOUT_FILENO);
	close(pfd[WRITE_END]);
	exec_cmd(cmd, envp);
}

/* Creates a new child process to execute the sent command in it */
static void	create_process(int fileout, char *cmd, char **envp)
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

/* Creates a new child process to execute the last command */
static void	last_cmd(int fileout, char *cmd, char **envp)
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

/* Executes all the commands */
void	run_cmd(t_cmd *data, char **argv, char **envp)
{
	while (data->cmd_index < data->last_cmd)
	{
		create_process(data->fileout, argv[data->cmd_index], envp);
		data->cmd_index++;
	}
	last_cmd(data->fileout, argv[data->cmd_index], envp);
}
