/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/06 14:54:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_list *list_a)
{
	t_list	*tmp;

	tmp = list_a->next;
	list_a->next = list_a;
	list_a = tmp;
}

void	swap_b(t_list *list_b)
{
	t_list	*tmp;

	tmp = list_b->next;
	list_b->next = list_b;
	list_b = tmp;
}

void	swap_both(t_list *list_a, t_list *list_b)
{
	swap_a(list_a);
	swap_b(list_b);
}
