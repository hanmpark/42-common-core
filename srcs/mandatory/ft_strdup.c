/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:07:05 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/12 15:12:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		i;
	int		count;
	char	*dest;

	i = ft_strlen(source) + 1;
	count = 0;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (0);
	while (source[count])
	{
		dest[count] = source[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
