/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 22:27:43 by hanmpark         ###   ########.fr       */
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

/* Put the top list of the chained list to the bottom */
void	rotate_list(t_list **list, int print)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	print_rotate(print);
	head = *list;
	next = head->next;
	last = ft_lstnew(head->number, head->index);
	ft_lstadd_back(list, last);
	ft_lstdelone(*list);
	*list = next;
}

/* Put the top of both chained lists to the bottom */
void	rotate_both(t_list **list_a, t_list **list_b)
{
	if (!*list_a || !*list_b || ft_lstsize(*list_a) < 2 || \
		ft_lstsize(*list_b) < 2)
		return ;
	ft_printf("rr\n");
	rotate_list(list_a, NO_PRINT);
	rotate_list(list_b, NO_PRINT);
}
