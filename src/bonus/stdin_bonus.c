/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:36:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 12:15:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Reads in the 'here_doc' */
static void	read_line(char *limiter, int *pfd)
{
	char	*gnl;

	close(pfd[READ_END]);
	gnl = get_next_line(0);
	while (gnl != NULL)
	{
		if (!ft_strncmp(gnl, limiter, ft_strlen(gnl) - 1))
		{
			free(gnl);
			close(pfd[WRITE_END]);
			exit(EXIT_SUCCESS);
		}
		write(pfd[WRITE_END], gnl, ft_strlen(gnl));
		free(gnl);
		gnl = get_next_line(0);
	}
}

/* HERE_DOC: writes to the pipe the here_doc and set its read-end to STDOUT */
void	here_doc(t_cmd *data, int argc, char **argv)
{
	int		pfd[2];
	int		pid;

	if (pipe(pfd) == - 1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_FORK);
	if (pid == CHILD_PROCESS)
		read_line(argv[2], pfd);
	close(pfd[WRITE_END]);
	dup2(pfd[READ_END], STDIN_FILENO);
	close(pfd[READ_END]);
	waitpid(pid, NULL, 0);
	data->fileOut = openFile(argv[argc - 1], APPEND);
	data->cmdIndex = 3;
}

/* INFILE: sets the content of the infile as the STDIN */
static void	infile(t_cmd *data, int argc, char **argv)
{
	int	fd;

	fd = openFile(argv[1], READ);
	dup2(fd, STDIN_FILENO);
	close(fd);
	data->fileOut = openFile(argv[argc - 1], WRITE);
	data->cmdIndex = 2;
}

/* Checks wether we have to treat the here_doc or the infile */
void	treatStdin(t_cmd *data, int argc, char **argv)
{
	data->lastCommand = argc - 2;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		if (argc < 5)
		{
			errno = EIO;
			ft_error(ERR_ARGS);
		}
		here_doc(data, argc, argv);
	}
	else
		infile(data, argc, argv);
}
