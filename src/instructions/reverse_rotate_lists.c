/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_lists.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **list_a, int print)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (print)
		ft_printf("rra\n");
	last = ft_lstlast(*list_a);
	new = ft_lstnew(last->number, last->index);
	ft_lstadd_front(list_a, new);
	current = *list_a;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstdelone(last);
}

void	reverse_rotate_b(t_list **list_b, int print)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (print)
		ft_printf("rrb\n");
	last = ft_lstlast(*list_b);
	new = ft_lstnew(last->number, last->index);
	ft_lstadd_front(list_b, new);
	current = *list_b;
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstdelone(last);
}

void	reverse_rotate_both(t_list **list_a, t_list **list_b, int print)
{
	if (print)
		ft_printf("rrr\n");
	reverse_rotate_a(list_a, NO_PRINT);
	reverse_rotate_b(list_b, NO_PRINT);
}
