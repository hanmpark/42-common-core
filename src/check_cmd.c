/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:25:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 23:37:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*defineCommandPath(char *cmd, char *env_path)
{
	char	**cmdPaths;
	char	*rightPath;
	char	*dirPath;
	int		i;

	cmdPaths = ft_split(env_path + 5, ':');
	i = 0;
	while (cmdPaths[i])
	{
		dirPath = ft_strjoin(cmdPaths[i], "/");
		rightPath = ft_strjoin(dirPath, cmd);
		free(dirPath);
		if (access(rightPath, F_OK) == 0)
		{
			ft_freestr_array(cmdPaths);
			return (rightPath);
		}
		free(rightPath);
		i++;
	}
	ft_freestr_array(cmdPaths);
	return (0);
}

char	*definePath(char **envp)
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

void	exec_cmd(t_cmd *data, char **cmd, char **envp)
{
	char	*cmd_path;

	if (!cmd)
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
