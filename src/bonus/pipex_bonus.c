/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/01 22:44:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "errors_bonus.h"

/* Pipex main function */
static void	pipex(t_cmd *data, int argc, char **argv, char **envp)
{
	treat_stdin(data, argc, argv);
	run_cmd(data, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	data;

	if (argc < 4)
	{
		errno = EIO;
		ft_error(ERR_ARGS);
	}
	pipex(&data, argc, argv, envp);
	return (0);
}
