/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:56:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/15 15:53:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"

/* Tells wether the index is in the bottom part / the upper part of the list */
int	half_locate(t_list **list, int index)
{
	t_list	*current;
	int		size;
	int		count;

	current = *list;
	count = 0;
	size = ft_lstsize(*list);
	while (current)
	{
		count++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	if ((size % 2 == 0 && count > size / 2) ||
		(size % 2 != 0 && count - 1 > size / 2))
		return (UPPER_HALF);
	return (BOTTOM_HALF);
}

/* Worthiest index to move from a list */
int	worthiest_index(t_list **list)
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

/* Strict superior index from a list */
int	strict_superior_index(t_list **list, int index)
{
	t_list	*current;
	int		ss_index;

	current = *list;
	ss_index = index + 1;
	while (current && current->index != ss_index)
	{
		current = current->next;
		if (current == NULL)
		{
			current = *list;
			ss_index++;
		}
	}
	return (ss_index);
}
