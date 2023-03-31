/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:33:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 15:24:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/pipex.h"
#include "main/errors.h"

/* Checks if the file exists */
static void	check_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN);
	close(fd);
}

/* Pipex main function */
static void	pipex(char **argv, char **envp)
{
	check_infile(argv[1]);
	check_cmd(argv, envp);
	run_cmd(argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		errno = EIO;
		ft_error(ERR_ARGS);
	}
	pipex(argv, envp);
	return (0);
}
