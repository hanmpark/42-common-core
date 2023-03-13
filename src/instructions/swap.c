/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 18:57:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap(int print)
{
	if (print == PRINT_A)
		ft_printf("sa\n");
	else if (print == PRINT_B)
		ft_printf("sb\n");
}

void	swap_list(t_list **list, int print)
{
	t_list	*current;
	t_list	*next;

	print_swap(print);
	current = *list;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list = next;
}

void	swap_both(t_list **list_a, t_list **list_b)
{
	ft_printf("ss\n");
	swap_list(list_a, NO_PRINT);
	swap_list(list_b, NO_PRINT);
}
