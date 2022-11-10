/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:01:57 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/10 18:14:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;

	if (size == 0 || !dst || !src)
		return (0);
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize >= size - 1)
		return (srcsize + size);
	else
	{
		while (dstsize + i < size - 1)
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		dst[dstsize + i] = '\0';
	}
	return (dstsize + srcsize);
}
/*#include <stdio.h>
int	main()
{
	char	first[] = "This is ";
	char	last[] = "a potentially long string";
	int		r;
	int		size = 8;
	char	buffer[size];

	strcpy(buffer, first);
	r = ft_strlcat(buffer, last, size);
	printf("%s\n", buffer);
	printf("Value returned: %d\n", r);
	if (r > size)
		printf("String truncated\n");
	else
		printf("String was fully copied\n");
	return (0);
}*/