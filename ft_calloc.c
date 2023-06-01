/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:22:47 by hanmpark          #+#    #+#             */
/*   Updated: 2023/06/01 07:24:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*var;

	if (count > UINT_MAX)
		return (NULL);
	var = malloc(count * size);
	if (!var)
		return (NULL);
	ft_bzero(var, count * size);
	return (var);
}
