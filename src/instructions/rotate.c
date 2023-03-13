/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 20:20:21 by hanmpark         ###   ########.fr       */
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

void	rotate_list(t_list **list, int print)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	print_rotate(print);
	head = *list;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(list, last);
	ft_lstdelone(*list);
	*list = next;
}

void	rotate_both(t_list **list_a, t_list **list_b)
{
	ft_printf("rr\n");
	rotate_list(list_a, NO_PRINT);
	rotate_list(list_b, NO_PRINT);
}
