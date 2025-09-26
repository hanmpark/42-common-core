/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:24:02 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:40:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcheck_order(t_list *pile)
{
	int	count;

	count = pile->index;
	while (pile)
	{
		if (pile->index != count)
			return (0);
		count++;
		pile = pile->next;
	}
	return (1);
}
