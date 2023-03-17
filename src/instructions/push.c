/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 16:35:47 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/instructions.h"

static void	print_push(int print)
{
	if (print == PRINT_A)
		ft_printf("pa\n");
	else if (print == PRINT_B)
		ft_printf("pb\n");
}

/* Push a list to the top of the other chained list */
void	push_list(t_list **from_list, t_list **to_list, int print)
{
	t_list	*current;
	t_list	*next;

	if (!*from_list)
		return ;
	print_push(print);
	current = *from_list;
	next = current->next;
	ft_lstadd_front(to_list, ft_lstnew(current->number, current->index));
	ft_lstdelone(*from_list);
	*from_list = next;
}
