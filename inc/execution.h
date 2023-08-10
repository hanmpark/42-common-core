/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:42:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/10 20:25:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define CHILD_PROCESS 0
# define WRITE_END 1
# define READ_END 0

# define EXEC_FAIL -1
# define PIPE_FAIL -1
# define FORK_FAIL -2
# define NO_CHILD_PROCESS -3

void	execute(t_mnsh *mnsh, t_tree *node);
int		parse_exec(t_mnsh *mnsh, t_cmd *cmd, int id, bool is_last);
void	set_redirection(t_cmd *cmd);
void	set_pipe_input(int *pfd, bool is_last_cmd);
void	set_pipe_output(int fdout, int *pfd, bool is_last_cmd);
void	reset_iostream(int *iostream);

char	**define_path_cmd(char **cmd_args, char *path);
char	*get_path(char **envp);

#endif