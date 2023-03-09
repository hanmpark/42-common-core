/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/09 16:29:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_a(t_list **list_b, t_list **list_a)
{
	t_list	*current;
	t_list	*next;

	current = *list_b;
	next = current->next;
	if (!*list_a)
		*list_a = ft_lstnew(current->number, current->index);
	else
		ft_lstadd_front(list_a, ft_lstnew(current->number, current->index));
	ft_lstdelone(current);
	*list_b = next;
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*current;
	t_list	*next;

	current = *list_a;
	next = current->next;
	if (!*list_b)
		*list_b = ft_lstnew(current->number, current->index);
	else
		ft_lstadd_front(list_b, ft_lstnew(current->number, current->index));
	ft_lstdelone(current);
	*list_a = next;
}
