/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 23:05:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	push_to_b(int max, t_list **list_a, t_list **list_b)
{
	t_list	*pushed_list;
	int		push_number;
	int		index;

	move_index_bottom(list_a, max, PRINT_A);
	index = 0;
	push_number = max - 2;
	pushed_list = NULL;
	while (index < push_number)
	{
		push_list(list_a, list_b, PRINT_B);
		pushed_list = *list_b;
		if (index > 0 && pushed_list->index > max / 2)
			rotate_list(list_b, PRINT_B);
		index++;
	}
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
	move_both_index(list_a, list_b, worthiest);
	push_list(list_b, list_a, PRINT_A);
}

void	sort_big_list(t_data *data)
{
	push_to_b(data->max_value, 2, &data->a, &data->b);
	while (data->b)
	{
		count_moves(&data->a, &data->b);
		push_to_a(&data->a, &data->b);
	}
	move_index_top(&data->a, 1, PRINT_A);
}

static void	push_small_b(int max, t_list **list_a, t_list **list_b)
{
	t_list	*pushed_list;
	int		push_number;
	int		index;

	move_three_bottom(list_a, max);
}

/*
** PUT THE ALGO TO ANOTHER FUNCTION
** AND MAKE ANTOHER FUNCTION FOR THE PUSH
** TRY TO FIND A BETTER NAME
*/

void	sort_small_list(t_list **list_a, t_list **list_b, int size)
{
	t_list	*last;
	t_list	*current;

	if (size > 3)
		push_small_b(size, );
	last = ft_lstlast(*list_a);
	current = *list_a;
	while (ft_lstcheck_order(*list_a) == FALSE)
	{
		if (last->index == current->index - 1)
		{
			if (current->index == 3)
				rotate_list(list_a, PRINT_A);
			else if (current->index == 2)
				reverse_rotate_list(list_a, PRINT_A);
		}
		else
			swap_list(list, PRINT_A);
		current = *list_a;
		last = ft_lstlast(*list_a);
	}
}
