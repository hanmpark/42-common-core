/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:25:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"
#include "../../../inc/instructions_bonus.h"

/* Swaps the first two lists of a chained lists */
void	swap_list(t_list **list)
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
	swap_list(list_a);
	swap_list(list_b);
}
