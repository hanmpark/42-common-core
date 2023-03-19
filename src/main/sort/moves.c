/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:12:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 13:57:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/instructions.h"
#include "main/locate.h"

/* Rotating or reverse_rotating until 'index' is at the top of the pile */
void	move_index_top(t_list **pile, int index, int print)
{
	t_list	*current;

	current = *pile;
	while (current && (current->index != index))
	{
		if (half_locate(pile, index) == BOTTOM_HALF)
			rotate_pile(pile, print);
		else if (half_locate(pile, index) == UPPER_HALF)
			reverse_rotate_pile(pile, print);
		current = *pile;
	}
}

/* Move the worthiest and the strict superior index to the top of the pile*/
void	move_both_index_top(t_list **pile_a, t_list **pile_b, int worthiest)
{
	t_list	*a;
	t_list	*b;
	int		nearest;

	a = *pile_a;
	b = *pile_b;
	nearest = strict_superior_index(pile_a, worthiest);
	while (a && b && a->index != nearest && b->index != worthiest)
	{
		if (half_locate(pile_a, nearest) == BOTTOM_HALF && \
			half_locate(pile_b, worthiest) == BOTTOM_HALF)
			rotate_both(pile_a, pile_b);
		else if (half_locate(pile_a, nearest) == UPPER_HALF && \
			half_locate(pile_b, worthiest) == UPPER_HALF)
			reverse_rotate_both(pile_a, pile_b);
		else
			break ;
		a = *pile_a;
		b = *pile_b;
	}
	move_index_top(pile_a, nearest, PRINT_A);
	move_index_top(pile_b, worthiest, PRINT_B);
}

/* Reorders the pile for three indexes */
void	reorder_small_pile(t_list **pile_a, int max)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(*pile_a);
	top = *pile_a;
	while (ft_lstcheck_order(*pile_a) == FALSE)
	{
		if (last->index == top->index - 1)
		{
			if (top->index == max)
				rotate_pile(pile_a, PRINT_A);
			else if (top->index == max - 1)
				reverse_rotate_pile(pile_a, PRINT_A);
		}
		else
			swap_pile(pile_a, PRINT_A);
		top = *pile_a;
		last = ft_lstlast(*pile_a);
	}
}
