/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:50:57 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "instructions_bonus.h"

/* Put the last list of a pile to the top */
void	rev_rot(t_list **pile)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (!*pile || ft_lstsize(*pile) < 2)
		return ;
	last = ft_lstlast(*pile);
	new = ft_lstnew(last->number, last->index);
	ft_lstadd_front(pile, new);
	current = *pile;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstdelone(last);
}

/* Put the last list of both piles to the top */
void	rev_rot_both(t_list **pile_a, t_list **pile_b)
{
	if (!*pile_a || !*pile_b || ft_lstsize(*pile_a) < 2 || \
		ft_lstsize(*pile_b) < 2)
		return ;
	rev_rot(pile_a);
	rev_rot(pile_b);
}
