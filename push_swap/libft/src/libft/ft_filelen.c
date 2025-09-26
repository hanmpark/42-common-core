/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:38:43 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 10:59:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_filelen(const char *file)
{
	char	*tmp;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	len = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		len++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (len);
}
