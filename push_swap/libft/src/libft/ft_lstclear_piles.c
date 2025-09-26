/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_piles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:03:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/21 13:04:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_piles(t_list **pile_a, t_list **pile_b)
{
	if (*pile_a)
		ft_lstclear(pile_a);
	if (*pile_b)
		ft_lstclear(pile_b);
}
