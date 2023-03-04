/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:32:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/04 14:41:28 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current_list;
	t_list	*next;

	if (lst)
	{
		current_list = *lst;
		while (current_list)
		{
			next = current_list->next;
			free(current_list);
			current_list = next;
		}
		*lst = NULL;
	}
}
