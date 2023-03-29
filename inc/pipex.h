/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/29 15:39:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define NOT_FOUND 0

typedef struct s_cmd
{
	int		pipe[2];
	int		nbrCommands;
	char	*envPath;
	char	**cmdPath;
}	t_cmd;

void	defineCommand(t_cmd *data, char **argv, char **envp);
void	checkInfile(char *Infile);
void	writeEnd(t_cmd *data, char **argv, char **envp);
void	readEnd(t_cmd *data, char **argv, char **envp);

#endif