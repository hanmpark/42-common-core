/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 18:43:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../../libft/inc/libft.h"
# include "../../libft/inc/get_next_line.h"

# define NOT_FOUND 0
# define READ 1
# define WRITE 2
# define APPEND 3

typedef struct s_cmd
{
	int		pipe[2];
	int		cmd;
	int		nbrCommands;
	char	*envPath;
	char	**cmdPath;
}	t_cmd;

void	defineCommand(t_cmd *data, char **argv, char **envp);

# endif