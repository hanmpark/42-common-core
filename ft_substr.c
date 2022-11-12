/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:11 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/12 16:40:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[start + i] = '\0';
	return (dest);
}
