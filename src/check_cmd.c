/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:25:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/27 18:58:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*choose_correctPath(char *cmd, char *env_path)
{
	char	**cmd_paths;
	char	*right_path;
	char	*path;
	int		i;

	cmd_paths = ft_split(env_path + 5, ':');
	i = 0;
	while (cmd_paths[i])
	{
		path = ft_strjoin(cmd_paths[i], "/");
		right_path = ft_strjoin(path, cmd);
		free(path);
		if (access(right_path, F_OK) == 0)
		{
			ft_freestr_array(cmd_paths);
			return (right_path);
		}
		free(right_path);
		i++;
	}
	ft_freestr_array(cmd_paths);
	return (0);
}

static char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NOT_FOUND)
			return (envp[i]);
		i++;
	}
	return (0);
}

void	exec_cmd(char **cmd, char **envp)
{
	char	*env_path;
	char	*cmd_path;

	if (!cmd)
		ft_error(ERR);
	env_path = find_path(envp);
	if (!env_path)
		ft_error(ERR);
	cmd_path = choose_correctPath(cmd[0], env_path);
	if (!cmd_path)
		ft_error(ERR);
	free(cmd[0]);
	cmd[0] = cmd_path;
	if (execve(cmd_path, cmd, envp) == -1)
	{
		free(cmd_path);
		ft_error(ERR);
	}
	free(cmd_path);
}
