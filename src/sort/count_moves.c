/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 17:09:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Number of moves done in 'B' to put the list to the top */
static void	count_list_b(t_list **list_b, t_list *b)
{
	t_list	*current;

	current = *list_b;
	while (current && (current->index != b->index))
	{
		b->moves++;
		current = current->next;
	}
	if (b->moves > ft_lstsize(*list_b) / 2)
		b->moves = ft_lstsize(*list_b) - b->moves;
	ft_printf("[%d] Moves in list_b = %d\n", b->index, b->moves);
}

/* Number of moves done in 'A' to put the list */
static void	count_list_a(t_list **list_a, t_list *b)
{
	t_list	*current;
	int		moves;

	current = *list_a;
	moves = 1;
	while (current && (b->index > current->index))
	{
		moves++;
		current = current->next;
	}
	if (moves - 1 > ft_lstsize(*list_a) / 2)
		moves = ft_lstsize(*list_a) - moves;
	b->moves += moves;
	ft_printf("[%d] Moves in list_a = %d\n\n", b->index, b->moves);
}

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
