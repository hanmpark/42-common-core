/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:40:59 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 08:03:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Treats the infile */
void	treatInfile(char *infile)
{
	int	fd;

	fd = openFile(infile, READ);
	if (fd == -1)
		ft_error(ERR_OPEN);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

/* Opens the file and returns its file descriptor */
int	openFile(char *fileName, int mode)
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
		ft_error(ERR_OPEN);
	return (fd);
}
