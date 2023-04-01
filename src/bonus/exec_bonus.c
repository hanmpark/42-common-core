/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/01 15:53:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Execute the sent command in the child process */
static void	exec_cmd(t_cmd *data, char *cmd, char **envp, int *pfd)
{
	char	**cmd_args;

	close(pfd[READ_END]);
	dup2(pfd[WRITE_END], STDOUT_FILENO);
	close(pfd[WRITE_END]);
	close(data->fileout);
	cmd_args = define_cmdargs(cmd, define_path(data->fileout, envp));
	if (execve(cmd_args[0], cmd_args, envp) == -1)
	{
		ft_freestr_array(cmd_args);
		ft_error(ERR_EXEC);
	}
}

/* Creates a new child process to execute the sent command in it */
static void	create_process(t_cmd *data, char *cmd, char **envp)
{
	int	pid;
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		close(data->fileout);
		ft_error(ERR_PIPE);
	}
	pid = fork();
	if (pid == -1)
	{
		close(data->fileout);
		close(pfd[READ_END]);
		close(pfd[WRITE_END]);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
		exec_cmd(data, cmd, envp, pfd);
	close(pfd[WRITE_END]);
	dup2(pfd[READ_END], STDIN_FILENO);
	close(pfd[READ_END]);
}

/* Creates a new child process to execute the last command */
static void	last_cmd(t_cmd *data, char *cmd, char **envp)
{
	char	**cmd_args;
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		close(data->fileout);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
	{
		dup2(data->fileout, STDOUT_FILENO);
		close(data->fileout);
		cmd_args = define_cmdargs(cmd, define_path(data->fileout, envp));
		if (execve(cmd_args[0], cmd_args, envp) == -1)
		{
			ft_freestr_array(cmd_args);
			ft_error(ERR_EXEC);
		}
	}
	waitpid(pid, NULL, 0);
}

/* Executes all the commands */
void	run_cmd(t_cmd *data, char **argv, char **envp)
{
	while (data->cmd_index < data->last_cmd)
	{
		create_process(data, argv[data->cmd_index], envp);
		data->cmd_index++;
	}
	last_cmd(data, argv[data->cmd_index], envp);
}
