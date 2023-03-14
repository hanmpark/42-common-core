/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:56:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 21:12:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"

/* function to see wether it's better to use 'rr' or 'r' */
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
int	worthiest_index(t_list **list_b)
{
	t_list	*current;
	int		moves;
	int		index;

	current = *list_b;
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

/* strict superior index from list_a */
int	strict_superior_index(t_list **list_a, int index)
{
	t_list	*current;
	int		ss_index;

	current = *list_a;
	ss_index = index + 1;
	while (current && current->index != ss_index)
	{
		current = current->next;
		if (current == NULL)
		{
			current = *list_a;
			ss_index++;
		}
	}
	return (ss_index);
}
