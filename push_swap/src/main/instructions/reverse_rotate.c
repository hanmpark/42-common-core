/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:21:58 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	print_reverse_rotate(int print)
{
	if (print == PRINT_A)
		ft_printf("rra\n");
	else if (print == PRINT_B)
		ft_printf("rrb\n");
}

/* Put the last list of a pile to the top */
void	reverse_rotate_pile(t_list **pile, int print)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (!*pile || ft_lstsize(*pile) < 2)
		return ;
	print_reverse_rotate(print);
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
void	reverse_rotate_both(t_list **pile_a, t_list **pile_b)
{
	if (!*pile_a || !*pile_b || ft_lstsize(*pile_a) < 2 || \
		ft_lstsize(*pile_b) < 2)
		return ;
	ft_printf("rrr\n");
	reverse_rotate_pile(pile_a, NO_PRINT);
	reverse_rotate_pile(pile_b, NO_PRINT);
}
