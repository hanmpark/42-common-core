/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:21:16 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/19 13:40:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*next;

	if (lst && f)
	{
		newlst = ft_lstnew(f(lst->content));
		if (lst->next)
		{
			next = ;
			if (f())
		}
	}
	
	return (NULL);
	return (newlst);
}