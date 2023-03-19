/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 13:58:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"

/* Number of moves done in 'B' to put the worthiest index to the top */
static void	count_list_b(t_list **pile_b, t_list *b)
{
	t_list	*current;

	current = *pile_b;
	while (current && current->index != b->index)
	{
		b->moves++;
		current = current->next;
	}
	if (b->moves > ft_lstsize(*pile_b) / 2)
		b->moves = ft_lstsize(*pile_b) - b->moves;
}

/* Number of moves done in 'A' to put the strict superior index to the top */
static void	count_list_a(t_list **pile_a, t_list *b)
{
	t_list	*current;
	int		moves;

	current = *pile_a;
	moves = 0;
	while (current && b->index > current->index)
	{
		moves++;
		current = current->next;
	}
	if (moves > ft_lstsize(*pile_a) / 2)
		moves = ft_lstsize(*pile_a) - moves;
	b->moves += moves;
}

/* Count the number of moves needed for a list to be pushed to a */
void	count_moves(t_list **pile_a, t_list **pile_b)
{
	t_list	*element;

	element = *pile_b;
	while (element)
	{
		count_list_b(pile_b, element);
		count_list_a(pile_a, element);
		element = element->next;
	}
}
