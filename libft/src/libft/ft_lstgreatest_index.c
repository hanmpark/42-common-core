/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgreatest_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:59 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 16:19:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstgreatest_index(t_list *list)
{
	int	greatest;

	greatest = list->index;
	while (list != NULL)
	{
		if (list->index > greatest)
			greatest = list->index;
		list = list->next;
	}
	return (greatest);
}
