/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:25:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 07:30:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errors.h"

/* Returns the PATH in envp */
char	*define_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != 0)
			return (envp[i]);
		i++;
	}
	ft_error(ERR_PATH);
	return (NULL);
}

/* Look for the right path for the command and returns the path as a string */
char	*define_cmdpath(char *cmd, char *env_path)
{
	char	**cmd_paths;
	char	*right_path;
	char	*dir_path;
	int		i;

	cmd_paths = ft_split(env_path + 5, ':');
	i = 0;
	while (cmd_paths[i])
	{
		dir_path = ft_strjoin(cmd_paths[i], "/");
		right_path = ft_strjoin(dir_path, cmd);
		free(dir_path);
		if (access(right_path, F_OK | X_OK) == 0)
		{
			ft_freestr_array(cmd_paths);
			return (right_path);
		}
		free(right_path);
		i++;
	}
	ft_freestr_array(cmd_paths);
	return (NULL);
}

/* Defines the cmd_args */
char	**define_cmdargs(char *cmd, char *path)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = define_cmdpath(cmd_args[0], path);
	if (cmd_path == NULL)
		return (cmd_args);
	free(cmd_args[0]);
	cmd_args[0] = cmd_path;
	return (cmd_args);
}

/* Defines the stdin */
void	define_stdin(char **argv, int fileout)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		close(fileout);
		ft_error(ERR_OPEN);
	}
	dup2(filein, STDIN_FILENO);
	close(filein);
}
