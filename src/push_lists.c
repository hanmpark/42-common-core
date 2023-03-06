/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/06 16:24:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(t_list *list_b, t_list *list_a)
{
	ft_lstadd_front(&list_a, list_b);
	list_b = list_b->next;
}

void	push_b(t_list *list_a, t_list *list_b)
{
	ft_lstadd_front(&list_b, list_a);
	list_a = list_a->next;
}
