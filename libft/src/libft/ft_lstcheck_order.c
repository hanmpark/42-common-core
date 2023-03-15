/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:24:02 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/15 15:25:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcheck_order(t_list *list_a)
{
	int	count;

	count = list_a->index;
	while (list_a)
	{
		if (list_a->index != count)
			return (0);
		count++;
		list_a = list_a->next;
	}
	return (1);
}
