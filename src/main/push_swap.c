/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/21 13:28:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/push_swap.h"
#include "main/parsing.h"
#include "main/instructions.h"

static void	sort_filter(t_data *data)
{
	if (ft_lstcheck_order(data->a) == TRUE)
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	data->max_value = ft_lstsize(data->a);
	if (data->max_value <= 5)
		sort_small_pile(&data->a, &data->b);
	else
		sort_big_pile(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	init_pile(&data, argv);
	sort_filter(&data);
	ft_lstclear(&data.a);
	return (0);
}
