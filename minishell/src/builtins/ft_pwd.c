/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:18:50 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/19 22:23:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "putft.h"

/*
* Pwd command:
* - stands for "Print Working Directory".
* - used to display the current working directory.
*/
int	ft_pwd(void)
{
	char	buf[4096];

	if (getcwd(buf, 4096) == NULL)
	{
		ft_putstr_fd(ERR_CWD, 2);
		return (1);
	}
	ft_putendl_fd(buf, STDOUT_FILENO);
	return (0);
}
