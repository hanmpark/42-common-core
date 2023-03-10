/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 10:54:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list_a)
{
	t_list	*current;
	t_list	*next;

	current = *list_a;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list_a = next;
}

void	swap_b(t_list **list_b)
{
	t_list	*current;
	t_list	*next;

	current = *list_b;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list_b = next;
}

void	swap_both(t_list **list_a, t_list **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
}
