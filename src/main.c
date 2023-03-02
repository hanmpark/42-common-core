/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/02 18:48:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_int(long nbr)
{
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (TRUE);
	return (FALSE);
}

static void	set_list(t_data *data, char **int_str, int index)
{
	int	i;

	i = 0;
	while (int_str && int_str[i])
	{
		if (check_int(ft_atol(int_str[i])) == FALSE)
		{
			ft_freemap(int_str);
			ft_error("Error\nParameter is not an int\n");
		}
		if (data->a == NULL)
			data->a = ft_lstnew(ft_atoi(int_str[i]), index);
		else
			ft_lstadd_back(&data->a, ft_lstnew(ft_atoi(int_str[i]), index));
		free(int_str[i]);
		i++;
	}
}

static void	init_list_a(t_data *data, int length, char **integers)
{
	long	number;
	char	**int_str;
	int		index;
	int		i;

	i = 1;
	index = 0;
	while (integers[i])
	{
		int_str = ft_split(integers[i], ' ');
		set_list(data, int_str, index);
		free(int_str);
		i++;
		index++;
	}
}

/* prints out the list but only for checking the parsing */
static void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("list[%d] = %d\n", list->index, list->number);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_list_a(&data, argc, argv);
	print_list(data.a); // checking if the parsing went well
	// system("leaks push_swap");
	return (0);
}
