/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:12:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 18:44:10 by hanmpark         ###   ########.fr       */
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
		if (list_location(list, current->index) == UPPER_HALF)
			rotate_list(list, print);
		else if (list_location(list, current->index) == BOTTOM_HALF)
			reverse_rotate_list(list, print);
		current = *list;
	}
}

/* rotating or reverse_rotating until 'index' is at the bottom of the list */
void	move_index_bottom(t_list **list, int index, int print)
{
	t_list	*current;

	current = ft_lstlast(*list);
	while (current && (current->index != index))
	{
		if (list_location(list, current->index) == UPPER_HALF)
			rotate_list(list, print);
		else if (list_location(list, current->index) == BOTTOM_HALF)
			reverse_rotate_list(list, print);
		current = ft_lstlast(*list);
	}
}

/* something incoming... */
void	move_index_ascending(t_list **list, int index, int print)
{
	t_list	*current;

	current = *list;
	while (current && (current->index > index))
	{
		
	}
}
