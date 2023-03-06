/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/06 18:20:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(t_list **list_a)
{
	t_list	*head;
	t_list	*last;

	head = *list_a;
	last = ft_lstnew(head->number);
	last->index = head->index;
	ft_lstadd_back(list_a, last);
	free(*list_a);
	*list_a = head->next;
}

void	rotate_b(t_list **list_b)
{
	t_list	*head;
	t_list	*last;

	head = *list_b;
	last = ft_lstnew(head->number);
	last->index = head->index;
	ft_lstadd_back(list_b, last);
	free(*list_b);
	*list_b = head->next;
}

void	rotate_both(t_list **list_a, t_list **list_b)
{
	rotate_a(list_a);
	rotate_b(list_b);
}
