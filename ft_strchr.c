/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:04:09 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:27:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)&(s[ft_strlen(s)]));
	while (*s && (char)c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "Hello World!";
	char	*r;
	char	ch = 0;

	r = strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, r);
	return (0);
}*/