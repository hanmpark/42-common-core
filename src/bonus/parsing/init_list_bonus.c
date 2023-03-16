/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:29:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:11:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"
#include "../../../inc/parsing_bonus.h"

static void	set_list(t_list **list, char **int_str)
{
	int	i;

	i = 0;
	while (int_str && int_str[i])
	{
		if (check_int_bonus(int_str[i]) == FALSE)
		{
			ft_freemap(int_str, i);
			ft_lsterror(list, ERR);
		}
		ft_lstadd_back(list, ft_lstnew(ft_atoi(int_str[i]), 0));
		free(int_str[i]);
		i++;
	}
}

/* Initialize the first list and parse it */
void	init_list_bonus(t_data *data, char **integers)
{
	char	**int_str;
	int		i;

	i = 1;
	while (integers[i])
	{
		int_str = ft_split(integers[i], ' ');
		set_list(&data->a, int_str);
		free(int_str);
		i++;
	}
	if (ft_lstsize(data->a) < 2)
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	check_duplicate_bonus(data->a);
	set_index_bonus(ft_lstsize(data->a), data->a);
}
