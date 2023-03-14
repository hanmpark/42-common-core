/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 12:10:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "locate.h"
#include "instructions.h"

static void	push_to_b(int max_value, t_list **list_a, t_list **list_b)
{
	t_list	*pushed_list;
	int		push_number;
	int		i;

	move_index_bottom(list_a, max_value, PRINT_A);
	i = 0;
	push_number = max_value - 2;
	pushed_list = NULL;
	while (i < push_number)
	{
		push_list(list_a, list_b, PRINT_B);
		pushed_list = *list_b;
		if (i > 0 && pushed_list->index > max_value / 2)
			rotate_list(list_b, PRINT_B);
		i++;
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

void	sort_small_list(t_list **list, int max_value)
{
	t_list	*current;
	t_list	*last;
	int		index;

	current = *list;
	index = 1;
	while (index < max_value)
	{
		index++;
	}
}
