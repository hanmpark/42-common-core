/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/instructions.h"

static void	print_swap(int print)
{
	if (print == PRINT_A)
		ft_printf("sa\n");
	else if (print == PRINT_B)
		ft_printf("sb\n");
}

/* Swaps the first two lists of a chained lists */
void	swap_list(t_list **list, int print)
{
	t_list	*current;
	t_list	*next;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	print_swap(print);
	current = *list;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list = next;
}
