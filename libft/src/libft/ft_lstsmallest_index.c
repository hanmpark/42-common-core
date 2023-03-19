/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmallest_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:50:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:40:47 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsmallest_index(t_list *pile)
{
	int	smallest;

	smallest = pile->index;
	while (pile != NULL)
	{
		if (pile->index < smallest)
			smallest = pile->index;
		pile = pile->next;
	}
	return (smallest);
}
