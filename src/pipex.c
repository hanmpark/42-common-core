/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:33:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 23:54:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	firstCommand(t_cmd *data, char *fileName, int *pipe)
{
	int		fileIn;
	char	**cmd;

	close(pipe[0]);
	fileIn = open(fileName, O_RDONLY);
	if (fileIn < 0)
		ft_error(ERR);
	cmd = ft_split(argv[2], ' ');
	dup2(fileIn, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	close(fileIn);
	exec_cmd(cmd);
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

/* Checks if the commands exist */
static void	checkCommands(t_cmd *data, char **argv)
{
	int		i;
	char	**cmdv;

	i = 0;
	data->cmdPath = ft_calloc(data->nbrCommands, sizeof(char *));
	if (data->cmdPath == NULL)
		ft_error(ERR_MALLOC);
	while (i < data->nbrCommands)
	{
		cmdv = ft_split(argv[2 + i], ' ');
		data->cmdPath[i] = defineCommandPath(cmdv[0], data->envPath);
		ft_freestr_array(cmdv);
		if (data->cmdPath[i] == NULL)
		{
			ft_freestr_array(data->cmdPath);
			ft_error(ERR_CMDPATH);
		}
		i++;
	}
}

static void	pipex(t_cmd *data, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error(ERR_PIPE);
	data->envPath = definePath(envp);
	if (data->envPath == NULL)
		ft_error(ERR_PATH);
	checkCommands(data, argv);
	pid = fork();
	if (pid == -1)
	{
		ft_freestr_array(data->cmdPath);
		ft_error(ERR_FORK);
	}
	else if (pid == 0)
		firstCommand(argv, envp, fd);
	waitpid(pid, NULL, 0);
	secondCommand(argv, envp, fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	data;

	if (argc != 5)
		ft_error(ERR_ARGS);
	data.nbrCommands = argc - 3;
	pipex(&data, argv, envp);
	return (0);
}
