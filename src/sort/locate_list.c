/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:56:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 19:07:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half_locate(t_list **list, int index)
{
	t_list	*current;
	int		count;

	current = *list;
	count = 0;
	while (current)
	{
		count++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	if (count > ft_lstsize(*list) / 2)
		return (UPPER_HALF);
	return (BOTTOM_HALF);
}

/* worthiest index to move from list_b */
int	index_to_move(t_list **list)
{
	t_list	*current;
	int		moves;
	int		index;

	current = *list;
	moves = current->moves;
	index = current->index;
	while (current)
	{
		if (current->moves < moves)
		{
			moves = current->moves;
			index = current->index;
		}
		current = current->next;
	}
	return (index);
}

int	nearest_index(t_list **list, int index)
{
	t_list	*current;
	int		asc_index;

	current = *list;
	asc_index = index + 1;
	while (current && current->index != asc_index)
	{
		current = current->next;
		if (current == NULL)
		{
			current = *list;
			asc_index++;
		}
	}
	return (asc_index);
}
