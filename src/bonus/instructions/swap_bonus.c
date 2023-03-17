/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 16:37:22 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"
#include "bonus/instructions_bonus.h"

/* Swaps the first two lists of a chained lists */
void	swap(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	current = *list;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list = next;
}

void	swap_both(t_list **list_a, t_list **list_b)
{
	if (!*list_a || !*list_b || ft_lstsize(*list_a) < 2 || \
		ft_lstsize(*list_b) < 2)
		return ;
	swap(list_a);
	swap(list_b);
}
