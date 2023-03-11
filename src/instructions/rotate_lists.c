/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 15:01:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **list_a, int print)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (print)
		ft_printf("ra\n");
	head = *list_a;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(list_a, last);
	free(*list_a);
	*list_a = next;
}

void	rotate_b(t_list **list_b, int print)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (print)
		ft_printf("rb\n");
	head = *list_b;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(list_b, last);
	free(*list_b);
	*list_b = next;
}

void	rotate_both(t_list **list_a, t_list **list_b, int print)
{
	if (print)
		ft_printf("rr\n");
	rotate_a(list_a, NO_PRINT);
	rotate_b(list_b, NO_PRINT);
}
