/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 22:54:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Pipex main function */
static void	pipex(t_cmd *data, int argc, char **argv, char **envp)
{
	int	pid;
	int	fileout;
	int	i;

	data->lastCommand = argc - 2;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		here_doc(data, argc, argv);
		fileout = openFile(data, argv[argc - 1], APPEND);
		data->cmd = 3;
	}
	else
	{
		treatInfile(data, argv[1], argc);
		fileout = openFile(data, argv[argc - 1], WRITE);
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
