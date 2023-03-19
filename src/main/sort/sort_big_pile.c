/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 13:53:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/locate.h"
#include "main/instructions.h"

static void	push_to_b(int max, t_list **pile_a, t_list **pile_b)
{
	t_list	*top;

	top = *pile_a;
	while (ft_lstsize(*pile_a) != 3)
	{
		if (top->index == max || top->index == max - 1 || \
			top->index == max - 2)
			rotate_pile(pile_a, PRINT_A);
		else
		{
			push_pile(pile_a, pile_b, PRINT_B);
			top = *pile_b;
			if (ft_lstsize(*pile_b) > 1 && top->index > max / 2)
				rotate_pile(pile_b, PRINT_B);
		}
		top = *pile_a;
	}
	reorder_small_pile(pile_a, max);
}

static void	push_to_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*b;
	int		worthiest;

	b = *pile_b;
	worthiest = worthiest_index(pile_b);
	ft_lstclear_moves(pile_b);
	if (b->next && b->next->index == worthiest)
		swap_pile(pile_b, PRINT_B);
	move_both_index_top(pile_a, pile_b, worthiest);
	push_pile(pile_b, pile_a, PRINT_A);
}

/* Sort big pile */
void	sort_big_pile(t_data *data)
{
	push_to_b(data->max_value, &data->a, &data->b);
	while (data->b)
	{
		count_moves(&data->a, &data->b);
		push_to_a(&data->a, &data->b);
	}
	move_index_top(&data->a, 1, PRINT_A);
}
