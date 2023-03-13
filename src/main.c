/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 20:45:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "instructions.h"

/* prints out the list but only for checking the parsing */
void	print_list(t_list *list, int print)
{
	if (print == PRINT_A)
		ft_printf("A LIST:\n");
	else if (print == PRINT_B)
		ft_printf("B LIST\n");
	while (list)
	{
		ft_printf("list[%d] = %d\n", list->index, list->number);
		list = list->next;
	}
	ft_printf("\n");
}

static void	sort_filter(t_data *data)
{
	if (ft_lstcheck_order(data->a) == TRUE)
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	if (ft_lstsize(data->a) <= 5)
		sort_small_list(data); // have to code it
	else
		sort_big_list(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	init_list(&data, argv);
	sort_filter(&data);
	ft_lstclear(&data.a);
	// system("leaks push_swap");
	return (0);
}
