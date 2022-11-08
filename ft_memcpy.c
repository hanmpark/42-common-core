/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:14 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/08 17:06:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t			i;

	destination = dest;
	source = src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return(dest);
}
/*#include <stdio.h>
int	main()
{
	char	str[50] = "Hello World!";
	char	str1[50] = "I don't really care";

	printf("%s\n", ft_memcpy(str, str1, strlen(str1) + 1));
	return (0);
}*/