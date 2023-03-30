/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execCommand_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:17:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 19:02:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Execute the command */
static void	exec_cmd(char **cmd, char **envp)
{
	if (execve(cmd[0], cmd, envp) == -1)
	{
		ft_freestr_array(cmd);
		ft_error(ERR_EXEC);
	}
}

/* Opens the file and returns its file descriptor */
static int	openFile(t_cmd *data, char *fileName, int mode)
{
	int	fd;

	fd = -1;
	if (mode == READ)
		fd = open(fileName, O_RDONLY);
	else if (mode == WRITE)
		fd = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	else if (mode == APPEND)
		fd = open(fileName, O_WRONLY | O_APPEND | O_CREAT, 0777);
	if (fd == -1)
	{
		close(data->pipe[0]);
		close(data->pipe[1]);
		ft_freestr_array(data->cmdPath);
		ft_error(ERR_OPEN);
	}
	return (fd);
}

/* Takes the 'infile' as the stdin for the command */
void	writeEnd(t_cmd *data, char **argv, char **envp)
{
	int		fileIn;
	char	**cmd;

	fileIn = openFile(data, argv[1], READ);
	close(data->pipe[0]);
	cmd = ft_split(argv[2], ' ');
	free(cmd[0]);
	cmd[0] = data->cmdPath[0];
	dup2(fileIn, STDIN_FILENO);
	dup2(data->pipe[1], STDOUT_FILENO);
	close(fileIn);
	close(data->pipe[1]);
	exec_cmd(cmd, envp);
}

void	runCommand(t_cmd *data, char **argv, char **envp)
{
	int	i;
	int	pid;

	i = 0;
	while (i < data->nbrCommands)
	{
		pid = fork();
		if (pid == 0)

		i++;
	}
}
