/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execCommand_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 23:22:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Execute the command */
static void	execCmd(char **cmd, char **envp)
{
	if (execve(cmd[0], cmd, envp) == -1)
	{
		ft_freestr_array(cmd);
		ft_error(ERR_EXEC);
	}
}

/* Takes the 'infile' as the stdin for the command */
void	execProcess(t_cmd *data, char *cmd, char **envp)
{
	char	**cmdArgs;
	int		pid;
	int		pfd[2];

	if (pipe(pfd) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
	{
		close(pfd[0]);
		close(pfd[1]);
		ft_error(ERR_FORK);
	}
	if (pid == 0)
	{
		close(pfd[0]);
		cmdArgs = ft_split(cmd, ' ');
		data->cmdPath = defineCommandPath(cmdArgs[0], data->envPath);
		free(cmdArgs[0]);
		cmdArgs[0] = data->cmdPath;
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		exec_cmd(cmdArgs, envp);
	}
}

void	runCommand(t_cmd *data, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < data->nbrCommands)
	{

		i++;
	}
}
