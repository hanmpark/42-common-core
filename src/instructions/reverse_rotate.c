/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 22:28:11 by hanmpark         ###   ########.fr       */
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

/* Put the last list of a chained list to the top */
void	reverse_rotate_list(t_list **list, int print)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	print_reverse_rotate(print);
	last = ft_lstlast(*list);
	new = ft_lstnew(last->number, last->index);
	ft_lstadd_front(list, new);
	current = *list;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstdelone(last);
}

/* Put the last list of both chained lists to the top */
void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	if (!*list_a || !*list_b || ft_lstsize(*list_a) < 2 || \
		ft_lstsize(*list_b) < 2)
		return ;
	ft_printf("rrr\n");
	reverse_rotate_list(list_a, NO_PRINT);
	reverse_rotate_list(list_b, NO_PRINT);
}
