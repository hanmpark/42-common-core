/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:22:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	print_rotate(int print)
{
	if (print == PRINT_A)
		ft_printf("ra\n");
	else if (print == PRINT_B)
		ft_printf("rb\n");
}

/* Put the top list of the pile to the bottom */
void	rotate_pile(t_list **pile, int print)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (!*pile || ft_lstsize(*pile) < 2)
		return ;
	print_rotate(print);
	head = *pile;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(pile, last);
	ft_lstdelone(*pile);
	*pile = next;
}

/* Put the top list of both piles to the bottom */
void	rotate_both(t_list **pile_a, t_list **pile_b)
{
	if (!*pile_a || !*pile_b || ft_lstsize(*pile_a) < 2 || \
		ft_lstsize(*pile_b) < 2)
		return ;
	ft_printf("rr\n");
	rotate_pile(pile_a, NO_PRINT);
	rotate_pile(pile_b, NO_PRINT);
}
