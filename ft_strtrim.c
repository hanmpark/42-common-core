/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:23:19 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/14 19:02:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_counttrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	countc;

	i = 0;
	countc = 0;
	while (s1[i])
	{
		if (i == 0 && ft_check(s1[i], set))
			countc++;
		else if (i == ft_strlen(s1) - 1 && ft_check(s1[i], set))
			countc++;
		i++;
	}
	countc = i - countc;
	return (countc);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	dstsize;
	size_t	i;

	if (!s1)
		return (NULL);
	dstsize = ft_counttrim(s1, set);
	dest = ft_calloc((dstsize + 1), sizeof(char));
	i = 0;
	if (i == 0 && ft_check(s1[i], set))
		i++;
	while (s1[i])
	{
		if (i == ft_strlen(s1) - 1 && ft_check(s1[i], set))
		{
			dest++;
			*dest = 0;
			return (dest);
		}
		*dest = s1[i];
		i++;
		dest++;
	}
	return (NULL);
}

#include <stdio.h>
int	main()
{
	char	s1[] = " Hello World !";
	char	set[] = " !";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}
