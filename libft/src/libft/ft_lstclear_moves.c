/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:02:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 17:02:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_moves(t_list **b)
{
	t_list	*current;

	current = *b;
	while (current)
	{
		current->moves = 0;
		current = current->next;
	}
}
