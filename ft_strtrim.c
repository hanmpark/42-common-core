/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:23:19 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/18 17:47:29 by hanmpark         ###   ########.fr       */
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
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	dstsize;
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == 0)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (s1[len - 1] && ft_strrchr(set, s1[len - 1]))
		len--;
	dstsize = len;
	dest = ft_substr(s1, 0, dstsize);
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	char	s1[] = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n";
	char	set[] = " \n\t";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
