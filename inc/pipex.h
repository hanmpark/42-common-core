/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 23:39:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

# define ERR "Error\n"
# define ERR_ARGS "Error\nWrong number of arguments\n"
# define ERR_PIPE "Error\nProblem occurred with pipe()\n"
# define ERR_FORK "Error\nProblem occurred with fork()\n"
# define ERR_MALLOC "Error\nProblem occurred with malloc()\n"
# define ERR_PATH "Error\nenvPath not found\n"
# define ERR_CMDPATH "Error\ncmdPath not found\n"

# define NOT_FOUND 0

typedef struct s_cmd
{
	int		nbrCommands;
	char	*envPath;
	char	**cmdPath;
}	t_cmd;

void	exec_cmd(t_cmd *data, char **cmd, char **envp);
char	*defineCommandPath(char *cmd, char *env_path);
char	*definePath(char **envp);

#endif