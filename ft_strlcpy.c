/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:25:40 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/10 12:47:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	destlen;
	size_t	sourcelen;
	size_t	i;

	destlen = strlen(dst);
	sourcelen = strlen(src);
	i = 0;
	if (dstsize - 1 <= destlen)
		return (sourcelen + dstsize);
	while (destlen + i < dstsize - 1)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + sourcelen);
}
#include <stdio.h>
int	main()
{
	char	str[] = "Hello there";
	char	buffer[19];
	int		r;

	r = strlcpy(buffer, str, 10);
	printf("Copied '%s' into '%s', length %d\n", str, buffer, r);
	r = ft_strlcpy(buffer, str, 10);
	printf("Copied '%s' into '%s', length %d\n", str, buffer, r);
	return (0);
}