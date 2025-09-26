/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:23:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	leave_three_lists(t_list **pile_a, t_list **pile_b, int size)
{
	t_list	*top;
	int		leave;

	top = *pile_a;
	leave = 0;
	while (size - leave != 3)
		leave++;
	while (ft_lstsize(*pile_a) != 3)
	{
		if (leave == 1 && (top->index == ft_lstsmallest_index(*pile_a) || \
			top->index == ft_lstgreatest_index(*pile_a)))
			push_pile(pile_a, pile_b, PRINT_B);
		else if (leave == 2 && top->index < 3)
			push_pile(pile_a, pile_b, PRINT_B);
		else
			rotate_pile(pile_a, PRINT_A);
		top = *pile_a;
	}
}

static void	push_back(t_list **pile_b, t_list **pile_a)
{
	if (half_locate(pile_b, ft_lstsmallest_index(*pile_b)) == BOTTOM_HALF)
		rotate_pile(pile_b, PRINT_B);
	while (*pile_b != NULL)
		push_pile(pile_b, pile_a, PRINT_A);
	move_index_top(pile_a, 1, PRINT_A);
}

/* Sort small pile */
void	sort_small_pile(t_list **pile_a, t_list **pile_b)
{
	if (ft_lstsize(*pile_a) > 3)
		leave_three_lists(pile_a, pile_b, ft_lstsize(*pile_a));
	reorder_small_pile(pile_a, ft_lstgreatest_index(*pile_a));
	if (*pile_b != NULL)
		push_back(pile_b, pile_a);
}
