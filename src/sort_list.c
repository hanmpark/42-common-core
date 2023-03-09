/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/09 18:24:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** array[] = {2, 4, 1, 3, 5};
** 2
** 4
** 1
** 3
** 5
*/

int	check_order(t_list *list_a)
{
	int	count;

	count = 1;
	while (list_a)
	{
		if (list_a->index != count)
			return (0);
		count++;
		list_a = list_a->next;
	}
	return (1);
}

int	check_median(t_list **list_a, int index)
{
	t_list	*current;

	current = *list_a;
	while (current)
	{
		if (current->index == index)
		{
			if (index <= ft_lstsize(*list_a) / 2)
				return (BOTTOM_HALF);
			else
				return (UPPER_HALF);
		}
		current = current->next;
	}
	return (-1);
}

void	max_to_bottom(t_list **list_a, int list_location)
{
	t_list	*comparative_list;

	comparative_list = NULL;
	while (1)
	{
		comparative_list = ft_lstlast(*list_a);
		if (comparative_list->index == ft_lstsize(*list_a))
			break ;
		if (list_location == BOTTOM_HALF)
			rotate_a(list_a);
		else if (list_location == UPPER_HALF)
			reverse_rotate_a(list_a);
	}
}

void	push_to_b(t_list **list_a, t_list **list_b)
{
	t_list	*current;

	current = *list_a;
	while (current)
	{
		if (current->index == ft_lstsize(*list_a))
			break ;
		current = current->next;
	}
	if (check_median(list_a, ft_lstsize(*list_a)) == BOTTOM_HALF)
		max_to_bottom(list_a, BOTTOM_HALF);
	else
		max_to_bottom(list_a, UPPER_HALF);
	int		times = ft_lstsize(*list_a) - 2;
	int		i = 0;
	while (i < times)
	{
		push_b(list_a, list_b);
		i++;
	}
}

void	sort_list(t_data *data)
{
	t_list	*current;

	current = data->a;
	if (check_order(current))
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	push_to_b(&data->a, &data->b);
}
