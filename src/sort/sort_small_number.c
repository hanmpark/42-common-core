/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/15 16:03:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	leave_three_lists(t_list **list_a, t_list **list_b)
{
	t_list	*top;

	top = *list_a;
	while (ft_lstsize(*list_a) != 3)
	{
		if (top->index > 3)
			push_list(list_a, list_b, PRINT_B);
		else if (top->next->index > 3 || top->next->next->index > 3)
			rotate_list(list_a, PRINT_A);
		else
			reverse_rotate_list(list_a, PRINT_A);
		top = *list_a;
	}
}

static void	push_back(t_list **list_b, t_list **list_a)
{
	if (half_locate(list_b, 4) == BOTTOM_HALF)
		rotate_list(list_b, PRINT_B);
	while (*list_b != NULL)
		push_list(list_b, list_a, PRINT_A);
	move_index_top(list_a, 1, PRINT_A);
}

/* Sort small chained list */
void	sort_small_list(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) > 3)
		leave_three_lists(list_a, list_b);
	reorder_list(list_a, 3);
	if (*list_b != NULL)
		push_back(list_b, list_a);
}
