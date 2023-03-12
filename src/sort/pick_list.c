/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:40:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 14:12:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
** 
** 
** 1 
** 2 3
** 5 4
*/