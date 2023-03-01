/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/01 18:35:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_list_a(t_data *data, int length, char **integers)
{
	int	i;

	data->a = ft_lstnew(ft_atoi(integers[1]), 0);
	i = 2;
	while (i < length)
	{

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
