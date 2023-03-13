/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:12:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 19:19:05 by hanmpark         ###   ########.fr       */
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
		if (half_locate(list, index) == BOTTOM_HALF)
			rotate_list(list, print);
		else if (half_locate(list, index) == UPPER_HALF)
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
		if (half_locate(list, index) == BOTTOM_HALF)
			rotate_list(list, print);
		else if (half_locate(list, index) == UPPER_HALF)
			reverse_rotate_list(list, print);
		last = ft_lstlast(*list);
	}
}

void	move_both_index(t_list **list_a, t_list **list_b, int worthiest)
{
	t_list	*a;
	t_list	*b;
	int		nearest;

	a = *list_a;
	b = *list_b;
	nearest = nearest_index(list_a, worthiest);
	while (a && b && a->index != nearest && b->index != worthiest)
	{
		if (half_locate(list_a, nearest) == BOTTOM_HALF &&
			half_locate(list_b, worthiest) == BOTTOM_HALF)
			rotate_both(list_a, list_b);
		else if (half_locate(list_a, nearest) == UPPER_HALF &&
			half_locate(list_b, worthiest) == UPPER_HALF)
			reverse_rotate_both(list_a, list_b);
		else
			break ;
		a = *list_a;
		b = *list_b;
	}
	move_index_top(list_a, nearest, PRINT_A);
	move_index_top(list_b, worthiest, PRINT_B);
}
