/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:23:25 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:31:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap_bonus.h"
#include "../../inc/instructions_bonus.h"
#include "../../inc/parsing_bonus.h"

static void	check_instruction(const char *arg, t_data *data)
{
	if (!ft_strncmp(arg, "sa\n", ft_strlen(arg)))
		swap_list(&data->a);
	else if (!ft_strncmp(arg, "sb\n", ft_strlen(arg)))
		swap_list(&data->b);
	else if (!ft_strncmp(arg, "ss\n", ft_strlen(arg)))
		swap_both(&data->a, &data->b);
	else if (!ft_strncmp(arg, "pa\n", ft_strlen(arg)))
		push_list(&data->b, &data->a);
	else if (!ft_strncmp(arg, "pb\n", ft_strlen(arg)))
		push_list(&data->a, &data->b);
	else if (!ft_strncmp(arg, "ra\n", ft_strlen(arg)))
		rotate_list(&data->a);
	else if (!ft_strncmp(arg, "rb\n", ft_strlen(arg)))
		rotate_list(&data->b);
	else if (!ft_strncmp(arg, "rr\n", ft_strlen(arg)))
		rotate_both(&data->a, &data->b);
	else if (!ft_strncmp(arg, "rra\n", ft_strlen(arg)))
		reverse_rotate_list(&data->a);
	else if (!ft_strncmp(arg, "rrb\n", ft_strlen(arg)))
		reverse_rotate_list(&data->b);
	else if (!ft_strncmp(arg, "rrr\n", ft_strlen(arg)))
		reverse_rotate_both(&data->a, &data->b);
	else
	{
		if (data->a)
			ft_lstclear(&data->a);
		if (data->b)
			ft_lstclear(&data->b);
		ft_error("Error\n");
	}
}

static void	wait_instructions(t_data *data)
{
	char	*gnl_return;

	gnl_return = get_next_line(0);
	while (gnl_return != NULL)
	{
		check_instruction(gnl_return, data);
		free(gnl_return);
		gnl_return = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	init_list_bonus(&data, argv);
	wait_instructions(&data);
	if (ft_lstcheck_order(data.a) == TRUE && data.b == NULL)
		ft_printf("OK\n");
	else if (ft_lstcheck_order(data.a) == FALSE || data.b != NULL)
		ft_printf("KO\n");
	if (data.a)
		ft_lstclear(&data.a);
	if (data.b)
		ft_lstclear(&data.b);
	return (0);
}
