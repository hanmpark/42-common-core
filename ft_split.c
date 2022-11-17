/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:37:17 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/17 10:30:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str && *str == c)
		str++;
	if (*str == 0)
		return (0);
	while (*str)
	{
		count++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (count);
}

char	*cpy_to_tab(char const *str, int start, int end)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc((end - start + 1) * sizeof(char));
	if (!tab)
		return (0);
	while (start < end)
	{
		tab[i] = str[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**tab;

	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				j++;
				s++;
			}
			*tab = cpy_to_tab(s, i, j);
			tab++;
			s - j;
		}
	}
	*tab++ = 0;
	return (tab - (count_words(s, c) + 1));
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "What a wonderful day !";
	char	sep = ' ';
	char	**nstrs;
	int		i;

	i = 0;
	nstrs = ft_split(str, sep);
	while (nstrs[i])
	{
		printf("%s\n", nstrs[i]); 
		free(nstrs[i]);
		i++;
	}
	free(nstrs[i]);
	return (0);
}*/