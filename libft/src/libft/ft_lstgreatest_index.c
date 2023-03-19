/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgreatest_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:59 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:39:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstgreatest_index(t_list *pile)
{
	int	greatest;

	greatest = pile->index;
	while (pile != NULL)
	{
		if (pile->index > greatest)
			greatest = pile->index;
		pile = pile->next;
	}
	return (greatest);
}
