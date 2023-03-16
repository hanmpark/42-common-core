/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:55 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:24:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"
#include "../../../inc/instructions_bonus.h"

/* Put the last list of a chained list to the top */
void	reverse_rotate_list(t_list **list)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
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
	reverse_rotate_list(list_a);
	reverse_rotate_list(list_b);
}
