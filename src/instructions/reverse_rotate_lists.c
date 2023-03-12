/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_lists.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 00:01:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_reverse_rotate(int print)
{
	if (print == PRINT_A)
		ft_printf("rra\n");
	else if (print == PRINT_B)
		ft_printf("rrb\n");
}

void	reverse_rotate_list(t_list **list, int print)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

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

void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	ft_printf("rrr\n");
	reverse_rotate_list(list_a, NO_PRINT);
	reverse_rotate_list(list_b, NO_PRINT);
}
