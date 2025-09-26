/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:21:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	print_push(int print)
{
	if (print == PRINT_A)
		ft_printf("pa\n");
	else if (print == PRINT_B)
		ft_printf("pb\n");
}

/* Push a list to the top of the other pile */
void	push_pile(t_list **from_pile, t_list **to_pile, int print)
{
	t_list	*current;
	t_list	*next;

	if (!*from_pile)
		return ;
	print_push(print);
	current = *from_pile;
	next = current->next;
	ft_lstadd_front(to_pile, ft_lstnew(current->number, current->index));
	ft_lstdelone(*from_pile);
	*from_pile = next;
}
