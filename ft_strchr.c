/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:04:09 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/17 10:30:12 by hanmpark         ###   ########.fr       */
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
	return (0);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "Hello WWorld!";
	char	*r;
	char	ch = 'W';
	
	r = ft_strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, r);
	return (0);
}*/