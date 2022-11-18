/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:11 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/18 00:59:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (*s == 0 || (size_t)start > ft_strlen(s) + 1)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i + start < ft_strlen(s) && s[start + i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "hola";
	char	*strsub;

	strsub = ft_substr(str, 2, 30);
	printf("%s\n", strsub);
	return (0);
}*/