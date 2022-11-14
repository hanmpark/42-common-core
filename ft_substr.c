/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:11 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/14 13:59:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(dest = malloc(1 * sizeof(char))))
			return (NULL);
		*dest = 0;
		return (dest);
	}
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
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