/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:01:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 10:22:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

static void	put_index_min(t_list *pile_a, int min, int index)
{
	t_list	*current_list;

	current_list = pile_a;
	while (current_list)
	{
		if (current_list->number == min)
			current_list->index = index;
		current_list = current_list->next;
	}
}

static int	set_min(t_list *pile_a)
{
	t_list	*current_list;
	int		min;

	current_list = pile_a;
	min = 0;
	while (current_list != NULL)
	{
		if (current_list->index == 0)
		{
			min = current_list->number;
			break ;
		}
		current_list = current_list->next;
	}
	return (min);
}

/* Set index to lists (better sorting experience) */
void	set_index(int length, t_list *pile_a)
{
	t_list	*current_list;
	int		min;
	int		index;

	index = 1;
	current_list = pile_a;
	while (index <= length)
	{
		min = set_min(pile_a);
		current_list = pile_a;
		while (current_list)
		{
			if (current_list->number < min && !current_list->index)
				min = current_list->number;
			current_list = current_list->next;
		}
		put_index_min(pile_a, min, index);
		index++;
	}
}
