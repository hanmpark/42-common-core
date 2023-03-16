/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:40:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	push_to_b(int max, t_list **list_a, t_list **list_b)
{
	t_list	*top;

	top = *list_a;
	while (ft_lstsize(*list_a) != 3)
	{
		if (top->index == max || top->index == max - 1 || \
			top->index == max - 2)
			rotate_list(list_a, PRINT_A);
		else
		{
			push_list(list_a, list_b, PRINT_B);
			if (ft_lstsize(*list_b) > 1 && top->index > max / 2)
				rotate_list(list_b, PRINT_B);
		}
		top = *list_a;
	}
	reorder_list(list_a, max);
}

static void	push_to_a(t_list **list_a, t_list **list_b)
{
	t_list	*b;
	int		worthiest;

	b = *list_b;
	worthiest = worthiest_index(list_b);
	ft_lstclear_moves(list_b);
	if (b->next && b->next->index == worthiest)
		swap_list(list_b, PRINT_B);
	move_both_index_top(list_a, list_b, worthiest);
	push_list(list_b, list_a, PRINT_A);
}

/* Sort big chained list */
void	sort_big_list(t_data *data)
{
	push_to_b(data->max_value, &data->a, &data->b);
	while (data->b)
	{
		count_moves(&data->a, &data->b);
		push_to_a(&data->a, &data->b);
	}
	move_index_top(&data->a, 1, PRINT_A);
}
