/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/10 13:33:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_position(t_list **list_a, int max_value)
{
	t_list	*current;

	current = *list_a;
	while (current)
	{
		if (current->index == max_value)
		{
			if (max_value <= ft_lstsize(*list_a) / 2)
				return (BOTTOM_HALF);
			else
				return (UPPER_HALF);
		}
		current = current->next;
	}
	return (-1);
}

static void	max_to_bottom(t_list **list_a, int max_value, int list_location)
{
	t_list	*comparative_list;

	comparative_list = ft_lstlast(*list_a);
	while (comparative_list->index != max_value)
	{
		if (list_location == BOTTOM_HALF)
			rotate_a(list_a, PRINT);
		else if (list_location == UPPER_HALF)
			reverse_rotate_a(list_a, PRINT);
		comparative_list = ft_lstlast(*list_a);
	}
}

// static void	presort_b(t_list **list_b)
// {

// }

// ft_lstsize(*list_a) in this function returns the max index value
void	push_to_b(int max_value, t_list **list_a, t_list **list_b)
{
	int	times;
	int	i;

	if (max_position(list_a, max_value) == BOTTOM_HALF)
		max_to_bottom(list_a, max_value, BOTTOM_HALF);
	else
		max_to_bottom(list_a, max_value, UPPER_HALF);
	i = 0;
	times = max_value - 2;
	while (i < times)
	{
		push_b(list_a, list_b, PRINT);
		// presort_b(list_b);
		i++;
	}
}
