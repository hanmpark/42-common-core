/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:12:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 00:13:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotating or reverse_rotating until 'index' is at the top of the list */
void	move_index_top(t_list **list, int index, int print)
{
	t_list	*current;

	current = *list;
	while (current && (current->index != index))
	{
		if (list_location(list, index) == BOTTOM_HALF)
			rotate_list(list, print);
		else if (list_location(list, index) == UPPER_HALF)
			reverse_rotate_list(list, print);
		current = *list;
	}
}

/* rotating or reverse_rotating until 'index' is at the bottom of the list */
void	move_index_bottom(t_list **list, int index, int print)
{
	t_list	*last;

	last = ft_lstlast(*list);
	while (last && (last->index != index))
	{
		if (list_location(list, index) == BOTTOM_HALF)
			rotate_list(list, print);
		else if (list_location(list, index) == UPPER_HALF)
			reverse_rotate_list(list, print);
		last = ft_lstlast(*list);
	}
}

/* something incoming... */
void	move_index_ascending(t_list **list, int index, int print)
{
	t_list	*current;
	int		asc_index;

	current = *list;
	asc_index = ascending_index(list, index);
	while (current && current->next->index != asc_index)
	{
		if (current->next->next->index == asc_index)
		{
			swap_list(list, print);
			break ;
		}
		if (list_location(list, asc_index) == BOTTOM_HALF)
		{
			swap_list(list, print);
			rotate_list(list, print);
		}
		else if (list_location(list, asc_index) == UPPER_HALF)
		{
			swap_list(list, print);
			reverse_rotate_list(list, print);
		}
		current = *list;
	}
}
