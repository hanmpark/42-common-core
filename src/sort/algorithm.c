/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 22:38:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(int max_value, t_list **list_a, t_list **list_b)
{
	int	times;
	int	i;

	move_index_bottom(list_a, max_value, PRINT_A);
	i = 0;
	times = max_value - 2;
	while (i < times)
	{
		push_list(list_a, list_b, PRINT_B);
		i++;
	}
}

void	pick_list(t_list **list_a, t_list **list_b)
{
	int	worthiest_index;

	worthiest_index = index_to_move(list_b);
	// ft_printf("worthiest_index = %d\n", worthiest_index);
	ft_lstclear_moves(list_b);
	move_index_top(list_b, worthiest_index, PRINT_B);
	push_list(list_b, list_a, PRINT_A);
	move_index_ascending(list_a, worthiest_index, PRINT_A);
}

void	reorder_list(t_list **list)
{
	t_list	*current;

	current = *list;
	while (current->index != 1)
	{
		if (list_location(list, 1) == BOTTOM_HALF)
			rotate_list(list, PRINT_A);
		else if (list_location(list, 1) == UPPER_HALF)
			reverse_rotate_list(list, PRINT_A);
		current = *list;
	}
}

void	sort_list(t_data *data)
{
	t_list	*current;

	current = data->a;
	if (ft_lstcheck_order(current))
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	data->max_value = ft_lstsize(data->a);
	push_to_b(data->max_value, &data->a, &data->b);
	while (data->b)
	{
		count_moves(&data->a, &data->b);
		pick_list(&data->a, &data->b);
	}
	reorder_list(&data->a);
	// count_moves(&data->a, &data->b);
	// pick_list(&data->a, &data->b);
}
