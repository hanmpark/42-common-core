/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 16:07:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	push_to_b(int max_value, t_list **list_a, t_list **list_b)
{
	t_list	*pushed_list;
	int		push_number;
	int		index;

	move_index_bottom(list_a, max_value, PRINT_A);
	index = 0;
	push_number = max_value - 2;
	pushed_list = NULL;
	while (index < push_number)
	{
		push_list(list_a, list_b, PRINT_B);
		pushed_list = *list_b;
		if (index > 0 && pushed_list->index > max_value / 2)
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
	push_to_b(data->max_value, &data->a, &data->b);
	while (data->b)
	{
		count_moves(&data->a, &data->b);
		push_to_a(&data->a, &data->b);
	}
	move_index_top(&data->a, 1, PRINT_A);
}

3
1
2

void	sort_small_list(t_list **list, int max_value)
{
	t_list	*last;
	t_list	*current;
	int		smallest;

	last = ft_lstlast(*list);
	current = *list;
	smallest = smallest_index(list);
	while (ft_lstcheck_order(*list) == FALSE)
	{
		if (current->index == smallest || current->index == max_value)
			swap_list(list, PRINT_A);
		else if (current->index == max_value - 1)
			rotate_list(list, PRINT_A);
		else if (last->index == max_value - 1)
			reverse_rotate_list(list, PRINT_A);
	}
}
