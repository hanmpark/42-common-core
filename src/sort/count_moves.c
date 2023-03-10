/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 15:00:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** array[] = {5, 2, 3, 1, 4}
** A  B
**    1
** 4  3
** 5  2
*/

void	count_list_b(t_list **list_b, int index)
{
	t_list	*b;

	b = *list_b;
	while (b->index != index)
	{
		b->moves++;
		b = b->next;
	}
	if (b->moves > ft_lstsize(*list_b) / 2);
		b->moves = ft_lstsize(*list_b) - b->moves;
}

int	count_moves(t_data *data, t_list **list_a, t_list **list_b)
{
	t_list	*b;

	b = *list_b;
	while (b)
	{
		set_moves(data, list_b, b->index);
		b = b->next;
	}
}
