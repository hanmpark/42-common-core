/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:18:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:42:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsterror(t_list **pile_a, t_list **pile_b, const char *error_message)
{
	if (*pile_a)
		ft_lstclear(pile_a);
	if (*pile_b)
		ft_lstclear(pile_b);
	if (error_message != NULL)
		ft_error(error_message);
}
