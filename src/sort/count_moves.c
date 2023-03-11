/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 15:11:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Number of moves done in 'B' to put the list to the top
void	count_list_b(t_list **list_b, t_list *b)
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

// Number of moves done in 'A' to put the list
void	count_list_a(t_list **list_a, t_list *b)
{
	t_list	*current;

	current = *list_a;
	b->moves++;
	while (current && (b->index > current->index))
	{
		b->moves++;
		current = current->next;
	}
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
