/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:57:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 11:09:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *message)
{
	ft_putstr_fd("\033[1;31m", 2);
	perror(message);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
