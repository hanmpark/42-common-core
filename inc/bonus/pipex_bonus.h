/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 08:09:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../../libft/inc/libft.h"
# include "../../libft/inc/get_next_line.h"
# include "../../libft/inc/ft_printf.h"

# define NOT_FOUND 0
# define READ 1
# define WRITE 2
# define APPEND 3

typedef struct s_cmd
{
	int		cmdIndex;
	int		lastCommand;
	int		fileOut;
	char	*envPath;
}	t_cmd;

void	checkCommand(t_cmd *data, char **argv, char **envp);
char	*defineCommandPath(char *cmd, char *envPath);
void	treatInfile(char *infile);
int		openFile(char *fileName, int mode);

void	here_doc(char **argv);

void	runCommand(t_cmd *data, char **argv, char **envp);

# endif