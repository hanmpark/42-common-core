/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execCommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:18:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/29 17:34:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errors.h"

/* Execute the command */
static void	exec_cmd(char **cmd, char **envp)
{
	if (execve(cmd[0], cmd, envp) == -1)
	{
		ft_freestr_array(cmd);
		ft_error(ERR_EXEC);
	}
}

/* Takes the 'infile' as the stdin for the command */
void	writeEnd(t_cmd *data, char **argv, char **envp)
{
	int		fileIn;
	char	**cmd;

	close(data->pipe[0]);
	fileIn = open(argv[1], O_RDONLY);
	if (fileIn == -1)
	{
		close(data->pipe[1]);
		ft_freestr_array(data->cmdPath);
		ft_error(ERR_OPEN);
	}
	cmd = ft_split(argv[2], ' ');
	free(cmd[0]);
	cmd[0] = data->cmdPath[0];
	dup2(fileIn, STDIN_FILENO);
	dup2(data->pipe[1], STDOUT_FILENO);
	close(fileIn);
	close(data->pipe[1]);
	exec_cmd(cmd, envp);
}

/* Takes the last output as the stdin for the command */
void	readEnd(t_cmd *data, char **argv, char **envp)
{
	int		fileOut;
	char	**cmd;

	close(data->pipe[1]);
	fileOut = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fileOut == -1)
	{
		close(data->pipe[0]);
		ft_freestr_array(data->cmdPath);
		ft_error(ERR_OPEN);
	}
	cmd = ft_split(argv[3], ' ');
	free(cmd[0]);
	cmd[0] = data->cmdPath[1];
	dup2(fileOut, STDOUT_FILENO);
	dup2(data->pipe[0], STDIN_FILENO);
	close(fileOut);
	close(data->pipe[0]);
	exec_cmd(cmd, envp);
}
