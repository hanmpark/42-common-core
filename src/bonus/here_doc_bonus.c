/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:01:16 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 08:01:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Reads in the 'here_doc' */
static void	read_line(char *limiter, int *pfd)
{
	char	*gnl;

	gnl = get_next_line(0);
	close(pfd[0]);
	while (gnl != NULL)
	{
		if (!ft_strncmp(gnl, limiter, ft_strlen(gnl)))
		{
			free(gnl);
			close(pfd[1]);
			exit(EXIT_SUCCESS);
		}
		write(pfd[1], gnl, ft_strlen(gnl));
		free(gnl);
		gnl = get_next_line(0);
	}
}

/* Writes to the pipe the stdin */
void	here_doc(char **argv)
{
	char	*gnl;
	int		pfd[2];
	int		pid;

	if (pipe(pfd) == - 1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_FORK);
	gnl = get_next_line(0);
	if (pid == 0)
		read_line(argv[2], pfd);
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	waitpid(pid, NULL, 0);
}
