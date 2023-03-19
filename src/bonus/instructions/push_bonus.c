/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 13:03:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"
#include "bonus/instructions_bonus.h"

/* Push a list to the top of the other pile */
void	push(t_list **from_pile, t_list **to_pile)
{
	t_list	*current;
	t_list	*next;

	if (!*from_pile)
		return ;
	current = *from_pile;
	next = current->next;
	ft_lstadd_front(to_pile, ft_lstnew(current->number, current->index));
	ft_lstdelone(*from_pile);
	*from_pile = next;
}
