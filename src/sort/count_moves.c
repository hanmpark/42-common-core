/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 07:42:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Number of moves done in 'B' to put the worthiest index to the top */
static void	count_list_b(t_list **list_b, t_list *b)
{
	t_list	*current;

	current = *list_b;
	while (current && current->index != b->index)
	{
		b->moves++;
		current = current->next;
	}
	if (b->moves > ft_lstsize(*list_b) / 2)
		b->moves = ft_lstsize(*list_b) - b->moves;
}

/* Number of moves done in 'A' to put the strict superior index to the top */
static void	count_list_a(t_list **list_a, t_list *b)
{
	t_list	*current;
	int		moves;

	current = *list_a;
	moves = 0;
	while (current && b->index > current->index)
	{
		moves++;
		current = current->next;
	}
	if (moves > ft_lstsize(*list_a) / 2)
		moves = ft_lstsize(*list_a) - moves;
	b->moves += moves;
}

/* Count the number of moves needed for a list to be pushed to a */
void	count_moves(t_list **list_a, t_list **list_b)
{
	t_list	*b;

	b = *list_b;
	while (b)
	{
		count_list_b(list_b, b);
		count_list_a(list_a, b);
		b = b->next;
	}
}