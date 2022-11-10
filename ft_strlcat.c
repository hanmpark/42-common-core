/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:01:57 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/10 16:48:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstsize;

	if (!dst || !src || !size)
		return (0);
	dstsize = ft_strlen(dst);
	i = dstsize + ft_strlen(src);
	while (*dst)
		dst++;
	size = size - 1 - dstsize;
	while (*src && size-- > 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (i);
}
/*#include <stdio.h>
int	main()
{
	char	first[] = "This is ";
	char	last[] = "a potentially long string";
	int		r;
	int		size = 16;
	char	buffer[size];

	strcpy(buffer, first);
	r = strlcat(buffer, last, size);
	printf("%s\n", buffer);
	printf("Value returned: %d\n", r);
	if (r > size)
		printf("String truncated\n");
	else
		printf("String was fully copied\n");
	return (0);
}*/