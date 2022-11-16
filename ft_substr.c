/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:11 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/16 12:03:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s) + 1)
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	if (len > ft_strlen(s))
		dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && i < ft_strlen(s))
	{
		dest[i] = s[(size_t)start + i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;

	strsub = ft_substr(str, 400, 20);
	printf("%s\n", strsub);
	return (0);
}*/