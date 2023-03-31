/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 12:27:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Execute the sent command in the child process */
static void	execCommand(t_cmd *data, char *cmd, char **envp, int *pfd)
{
	char	**cmdArgs;
	char	*cmdPath;

	close(pfd[READ_END]);
	cmdArgs = ft_split(cmd, ' ');
	cmdPath = defineCommandPath(cmdArgs[0], data->envPath);
	free(cmdArgs[0]);
	cmdArgs[0] = cmdPath;
	dup2(pfd[WRITE_END], STDOUT_FILENO);
	close(pfd[WRITE_END]);
	execve(cmdPath, cmdArgs, envp);
}

/* Creates a new child process to execute the sent command in it */
static void	createProcess(t_cmd *data, char *cmd, char **envp)
{
	int		pid;
	int		pfd[2];

	if (pipe(pfd) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
	{
		close(pfd[READ_END]);
		close(pfd[WRITE_END]);
		close(data->fileOut);
		ft_error(ERR_FORK);
	}
	if (pid == CHILD_PROCESS)
		execCommand(data, cmd, envp, pfd);
	close(pfd[WRITE_END]);
	dup2(pfd[READ_END], STDIN_FILENO);
	close(pfd[READ_END]);
}

/* Creates a new child process to execute the last command */
static void	lastCommand(t_cmd *data, char *cmd, char **envp)
{
	char	**cmdArgs;
	char	*cmdPath;
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_error(ERR_FORK);
	if (pid == CHILD_PROCESS)
	{
		dup2(data->fileOut, STDOUT_FILENO);
		close(data->fileOut);
		cmdArgs = ft_split(cmd, ' ');
		cmdPath = defineCommandPath(cmdArgs[0], data->envPath);
		free(cmdArgs[0]);
		cmdArgs[0] = cmdPath;
		execve(cmdPath, cmdArgs, envp);
	}
	waitpid(pid, NULL, 0);
}

/* Executes all the commands */
void	runCommand(t_cmd *data, char **argv, char **envp)
{
	while (data->cmdIndex < data->lastCommand)
	{
		createProcess(data, argv[data->cmdIndex], envp);
		data->cmdIndex++;
	}
	lastCommand(data, argv[data->cmdIndex], envp);
}
