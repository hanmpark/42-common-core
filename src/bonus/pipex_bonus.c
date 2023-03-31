/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 15:36:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/pipex_bonus.h"
#include "bonus/errors_bonus.h"

/* Pipex main function */
static void	pipex(t_cmd *data, int argc, char **argv, char **envp)
{
	treat_stdin(data, argc, argv);
	check_cmd(data, argv, envp);
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
