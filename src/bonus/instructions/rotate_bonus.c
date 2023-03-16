/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:21 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:24:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"
#include "../../../inc/instructions_bonus.h"

/* Put the top list of the chained list to the bottom */
void	rotate_list(t_list **list)
{
	t_list	*head;
	t_list	*last;
	t_list	*next;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
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
	rotate_list(list_a);
	rotate_list(list_b);
}
