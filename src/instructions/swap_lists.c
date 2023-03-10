/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 11:48:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list_a, int print)
{
	t_list	*current;
	t_list	*next;

	if (print)
		ft_printf("sa\n");
	current = *list_a;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list_a = next;
}

void	swap_b(t_list **list_b, int print)
{
	t_list	*current;
	t_list	*next;

	if (print)
		ft_printf("sb\n");
	current = *list_b;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list_b = next;
}

void	swap_both(t_list **list_a, t_list **list_b, int print)
{
	if (print)
		ft_printf("ss\n");
	swap_a(list_a, NO_PRINT);
	swap_b(list_b, NO_PRINT);
}
