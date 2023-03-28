/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 22:23:01 by hanmpark         ###   ########.fr       */
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
# define ERR_PIPE "Error\nProblem occurred in pipe()\n"
# define ERR_FORK "Error\nProblem occurred in fork()\n"

# define NOT_FOUND 0

void	exec_cmd(char **cmd, char **envp);

#endif