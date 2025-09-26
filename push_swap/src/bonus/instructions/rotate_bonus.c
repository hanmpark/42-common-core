/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:51:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "instructions_bonus.h"

/* Put the top list of the pile to the bottom */
void	rot(t_list **pile)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (!*pile || ft_lstsize(*pile) < 2)
		return ;
	head = *pile;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(pile, last);
	ft_lstdelone(*pile);
	*pile = next;
}

/* Put the top list of both piles to the bottom */
void	rot_both(t_list **pile_a, t_list **pile_b)
{
	if (!*pile_a || !*pile_b || ft_lstsize(*pile_a) < 2 || \
		ft_lstsize(*pile_b) < 2)
		return ;
	rot(pile_a);
	rot(pile_b);
}
