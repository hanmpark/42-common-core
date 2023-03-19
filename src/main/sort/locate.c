/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:56:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 13:57:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/locate.h"

/* Tells wether the index is in the bottom part / the upper part of the pile */
int	half_locate(t_list **pile, int index)
{
	t_list	*current;
	int		size;
	int		count;

	current = *pile;
	count = 0;
	size = ft_lstsize(*pile);
	while (current)
	{
		count++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	if ((size % 2 == 0 && count > size / 2) || \
		(size % 2 != 0 && count - 1 > size / 2))
		return (UPPER_HALF);
	return (BOTTOM_HALF);
}

/* Worthiest index to move from a pile */
int	worthiest_index(t_list **pile)
{
	t_list	*current;
	int		moves;
	int		index;

	current = *pile;
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

/* Strict superior index from a pile */
int	strict_superior_index(t_list **pile, int index)
{
	t_list	*current;
	int		ss_index;

	current = *pile;
	ss_index = index + 1;
	while (current && current->index != ss_index)
	{
		current = current->next;
		if (current == NULL)
		{
			current = *pile;
			ss_index++;
		}
	}
	return (ss_index);
}
