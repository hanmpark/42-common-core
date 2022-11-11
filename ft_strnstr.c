/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:47 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 19:54:22 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		f;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	if (!len)
		return (0);
	if (ft_strlen(needle) > len)
		return (0);
	while ((char)haystack[i] && len)
	{
		f = 0;
		while ((char)haystack[i] == (char)needle[f] && len--)
		{
			i++;
			f++;
			if ((char)needle[f] == '\0')
				return ((char *)haystack + i - f);
		}
		i -= f;
		len += f;
		len--;
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char	*r;

	r = ft_strnstr(haystack, "cd", 8);
	printf("%s\n", r);
	return (0);
}*/