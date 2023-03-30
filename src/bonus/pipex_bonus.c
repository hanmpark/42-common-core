/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 18:46:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Checks if the file exists */
static void	checkInfile(t_cmd *data, char *infile, int argc)
{
	int	fd;

	data->nbrCommands = argc - 3;
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN);
	close(fd);
}

/* Creates a new child process */
static int	createProcess(t_cmd *data)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_freestr_array(data->cmdPath);
		ft_error(ERR_FORK);
	}
	return (pid);
}

/* Writes to the pipe the stdin */
static void	here_doc(t_cmd *data, int argc, char **argv)
{
	char	*limiter;
	char	*gnl;
	int		pid;

	data->nbrCommands = argc - 4;
	pid = createProcess(data);
	limiter = argv[2];
	gnl = get_next_line(0);
	if (pid == 0)
	{
		close(data->pipe[0]);
		while (gnl != NULL)
		{
			if (!ft_strncmp(gnl, limiter, ft_strlen(gnl)))
			{
				free(gnl);
				close(data->pipe[1]);
				exit(EXIT_SUCCESS);
			}
			write(data->pipe[1], gnl, ft_strlen(gnl));
			free(gnl);
			gnl = get_next_line(0);
		}
		close(data->pipe[1]);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
}

/* Pipex main function */
static void	pipex(t_cmd *data, int argc, char **argv, char **envp)
{
	int	pid;
	int	i;

	data->cmd = 1;
	if (pipe(data->pipe) == -1)
		ft_error(ERR_PIPE);
	if (!ft_strncmp(argv[data->cmd], "here_doc", ft_strlen(argv[data->cmd])))
	{
		here_doc(data, argc, argv);
		data->cmd = 3;
	}
	else
	{
		checkInfile(data, argv[i], argc);
		data->cmd = 2;
	}
	defineCommand(data, argv, envp);
	runCommand(data, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	data;

	if (argc < 5)
	{
		errno = EIO;
		ft_error(ERR_ARGS);
	}
	pipex(&data, argc, argv, envp);
	return (0);
}
