/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/01 19:28:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_list_a(t_data *data, int length, char **integers)
{
	char	**str;
	int		index;
	int		i;
	int		j;

	index = 0;
	data->a = ft_lstnew(ft_atoi(integers[1]), index);
	i = 2;
	while (i < length)
	{
		str = ft_split(integers[i], ' ');
		j = 0;
		while (str && str[j])
		{
			index++;
			ft_lstadd_back(&data->a, ft_lstnew(ft_atoi(str[i]), index));
			j++;
		}
	}
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_list_a(&data, argc, argv);
	return (0);
}
