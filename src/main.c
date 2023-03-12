/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 14:10:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_order(t_list *list_a)
{
	int	count;

	count = 1;
	while (list_a)
	{
		if (list_a->index != count)
			return (0);
		count++;
		list_a = list_a->next;
	}
	return (1);
}

static void	sort_list(t_data *data)
{
	t_list	*current;

	current = data->a;
	if (check_order(current))
	{
		ft_lstclear(&data->a);
		exit(0);
	}
	data->max_value = ft_lstsize(data->a);
	push_to_b(data->max_value, &data->a, &data->b);
	count_moves(&data->a, &data->b);
	pick_list(&data->a, &data->b);
}

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	init_list_a(&data, argv);
	ft_printf("Before sort:\n");
	print_list(data.a, PRINT_A);
	sort_list(&data);
	ft_printf("\nAfter sort:\n");
	print_list(data.a, PRINT_A);
	print_list(data.b, PRINT_B);
	// system("leaks push_swap");
	return (0);
}
