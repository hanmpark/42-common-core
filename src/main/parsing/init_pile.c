/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:29:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/21 13:28:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/parsing.h"

static void	set_pile(t_list **pile, char **int_str)
{
	int	i;

	i = 0;
	while (int_str && int_str[i])
	{
		if (check_int(int_str[i]) == FALSE)
		{
			ft_freemap(int_str, i);
			ft_lstclear(pile);
			ft_strexit(ERR, 1);
		}
		ft_lstadd_back(pile, ft_lstnew(ft_atoi(int_str[i]), 0));
		free(int_str[i]);
		i++;
	}
}

/* Initialize the first pile and parse it */
void	init_pile(t_data *data, char **integers)
{
	char	**int_str;
	int		i;

	i = 1;
	while (integers[i])
	{
		int_str = ft_split(integers[i], ' ');
		set_pile(&data->a, int_str);
		free(int_str);
		i++;
	}
	if (ft_lstsize(data->a) < 2)
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	check_duplicate(data->a);
	set_index(ft_lstsize(data->a), data->a);
}
