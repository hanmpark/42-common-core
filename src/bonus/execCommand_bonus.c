/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execCommand_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 08:15:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Execute the command */
static void	execCmd(int fileOut, char **cmd, char **envp)
{
	if (execve(cmd[0], cmd, envp) == -1)
	{
		close(fileOut);
		ft_freestr_array(cmd);
		ft_error(ERR_EXEC);
	}
}

/* Takes the 'infile' as the stdin for the command */
void	execProcess(t_cmd *data, char *cmd, char **envp)
{
	char	**cmdArgs;
	char	*cmdPath;
	int		pid;
	int		pfd[2];

	if (pipe(pfd) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
	{
		close(pfd[0]);
		close(pfd[1]);
		close(data->fileOut);
		ft_error(ERR_FORK);
	}
	if (pid == 0)
	{
		close(pfd[0]);
		cmdArgs = ft_split(cmd, ' ');
		cmdPath = defineCommandPath(cmdArgs[0], data->envPath);
		free(cmdArgs[0]);
		cmdArgs[0] = cmdPath;
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		execCmd(data->fileOut, cmdArgs, envp);
	}
	close(pfd[0]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	waitpid(pid, NULL, 0);
}

static void	lastCommand(t_cmd *data, char *cmd, char **envp)
{
	char	**cmdArgs;
	char	*cmdPath;
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_error(ERR_PIPE);
	if (pid == 0)
	{
		cmdArgs = ft_split(cmd, ' ');
		cmdPath = defineCommandPath(cmdArgs[0], data->envPath);
		ft_printf("cmdPath for the last command is %s\n", cmdPath);
		ft_printf("cmdArgs = %s\n\n", cmdArgs[1]);
		free(cmdArgs[0]);
		cmdArgs[0] = cmdPath;
		execCmd(data->fileOut, cmdArgs, envp);
	}
	waitpid(pid, NULL, 0);
}

void	runCommand(t_cmd *data, char **argv, char **envp)
{
	while (data->cmdIndex < data->lastCommand)
	{
		ft_printf("runCommand() entered in the loop, at cmdIndex = %d\n", data->cmdIndex);
		ft_printf("-> cmd = %s\n\n", argv[data->cmdIndex]);
		execProcess(data, argv[data->cmdIndex], envp);
		data->cmdIndex++;
	}
	ft_printf("The last command is %s\n\n", argv[data->cmdIndex]);
	lastCommand(data, argv[data->cmdIndex], envp);
}
