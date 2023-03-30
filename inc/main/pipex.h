/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 11:43:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../../libft/inc/libft.h"

# define NOT_FOUND 0
# define READ 1
# define WRITE 2

typedef struct s_cmd
{
	int		pipe[2];
	int		nbrCommands;
	char	*envPath;
	char	**cmdPath;
}	t_cmd;

void	defineCommand(t_cmd *data, char **argv, char **envp);
void	writeEnd(t_cmd *data, char **argv, char **envp);
void	readEnd(t_cmd *data, char **argv, char **envp);

#endif