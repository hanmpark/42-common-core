/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 15:27:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include "../../libft/inc/libft.h"
# include "../../libft/inc/get_next_line.h"

/* Pipe's ends */
# define READ_END 0
# define WRITE_END 1

/* Process id */
# define CHILD_PROCESS 0

/* Modes for openFile() */
# define READ 1
# define WRITE 2
# define APPEND 3

typedef struct s_cmd
{
	int		cmd_index;
	int		last_cmd;
	int		fileout;
	char	*env_path;
}	t_cmd;

void	treat_stdin(t_cmd *data, int argc, char **argv);
void	check_cmd(t_cmd *data, char **argv, char **envp);
void	run_cmd(t_cmd *data, char **argv, char **envp);

char	*define_cmdpath(char *cmd, char *envPath);
char	**define_cmdargs(char *cmd, char *path);
int		open_file(char *fileName, int mode);

#endif