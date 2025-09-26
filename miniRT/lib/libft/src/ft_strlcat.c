/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:27:14 by yobouhle          #+#    #+#             */
/*   Updated: 2022/11/07 14:27:17 by yobouhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	char	*p_src;

	size_dest = 0;
	if (dest != NULL)
		size_dest = ft_strlen(dest);
	p_src = (char *)src;
	if (size_dest >= size)
		return (size + ft_strlen(src));
	while (*dest)
		dest++;
	while (*p_src && size_dest + (p_src - src) < (size - 1))
		*dest++ = *p_src++;
	*dest = '\0';
	return (size_dest + ft_strlen(src));
}
