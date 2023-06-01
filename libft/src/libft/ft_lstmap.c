/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:21:16 by hanmpark          #+#    #+#             */
/*   Updated: 2023/06/01 10:27:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies a function to each element of a linked list and creates a new list
* with the modified elements.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*next;

	if (!lst && !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, next);
		lst = lst->next;
	}
	return (newlst);
}
