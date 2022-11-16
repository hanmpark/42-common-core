/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:23:19 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/16 07:34:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	The function allocates with malloc and return a copy of the 's1' string
	without the characters specified in 'set' at the beginning et at the end
	of the string.
	1. Does 's1' exists ?
	2. What if 'set' doesn't exist ?
	3. What does the function :
		- checks if characters of set exist at the beginning or the end of 's1'
	--> strchr does it
		- if it is the case, they will not appear in the new str
		- if not, it will just ignore it
		- malloc, cpy etc.
*/

int	found_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	char	*dststart;
	char	*dstend;
	size_t	dstsize;
	size_t	i;

	if (!s1 || !set)
		return (0);
	if (s1[0] == 0)
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && found_in_set(s1[i], set))
		i++;
	dststart = (char *)&s1[i];
	i = 0;
	while (s1[ft_strlen(s1) - 1 - i]
		&& found_in_set(s1[ft_strlen(s1) - 1 - i], set))
		i++;
	dstend = (char *)&s1[ft_strlen(s1) - 1 - i];
	dstsize = ft_strlen(dststart) - ft_strlen(dstend) + 1;
	dest = malloc((dstsize + 1) * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, dststart, dstsize + 1);
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	s1[] = "";
	char	set[] = "";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}*/
