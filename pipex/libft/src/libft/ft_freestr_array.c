/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:30:51 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/28 22:06:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestr_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array && str_array[i])
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
	}
}
