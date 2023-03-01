/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:36:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/01 17:45:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_error(const char *message)
{
	ft_printf("%s%s%s%s", BOLD, RED, message, DEF);
	exit(1);
}
