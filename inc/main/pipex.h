/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/01 16:08:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include "../../libft/inc/libft.h"

/* Pipe's ends */
# define READ_END 0
# define WRITE_END 1

/* Process id */
# define CHILD_PROCESS 0

void	run_cmd(char **argv, char **envp);

char	*define_cmdpath(char *cmd, char *envPath);
char	**define_cmdargs(char *cmd, char *path);
char	*define_path(char **envp);

#endif