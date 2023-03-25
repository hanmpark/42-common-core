/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:33:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/25 15:18:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		return 1;
	pid1 = fork();
	if (pid1 < 0)
		return 2;
	if (pid1 == 0)
	{
		// Child process
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("")
	}
	return (0);
}
