/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:13:37 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 15:18:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (!c)
		return ((char *)&(s[ft_strlen(s)]));
	ptr = NULL;
	while (*s && (unsigned char)c)
	{
		if (*s == (unsigned char)c)
			ptr = ((char *)&(*s));
		s++;
	}
	return (ptr);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "abbbbbbbb";
	char	str1[] = "abbbbbbbb";
	char	*r;
	char	*o;
	char	ch = 'a';

	r = ft_strrchr(str, ch);
	o = strrchr(str1, ch);
	printf("String after |%c| is - |%s|\n", ch, r);
	printf("String after |%c| is - |%s|\n", ch, o);
	return (0);
}*/