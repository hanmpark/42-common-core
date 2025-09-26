/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:51:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "instructions_bonus.h"

/* Swaps the first two lists of a pile */
void	swap(t_list **pile)
{
	t_list	*current;
	t_list	*next;

	if (!*pile || ft_lstsize(*pile) < 2)
		return ;
	current = *pile;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*pile = next;
}

/* Swaps the first two lists of both piles */
void	swap_both(t_list **pile_a, t_list **pile_b)
{
	if (!*pile_a || !*pile_b || ft_lstsize(*pile_a) < 2 || \
		ft_lstsize(*pile_b) < 2)
		return ;
	swap(pile_a);
	swap(pile_b);
}
