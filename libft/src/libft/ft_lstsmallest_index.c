/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmallest_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:50:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 18:51:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsmallest_index(t_list *list)
{
	int	smallest;

	smallest = list->index;
	while (list != NULL)
	{
		if (list->index < smallest)
			smallest = list->index;
		list = list->next;
	}
	return (smallest);
}
