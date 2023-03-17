/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:23:25 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 19:22:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"
#include "bonus/instructions_bonus.h"
#include "bonus/parsing_bonus.h"

static int	check_instruction(const char *arg, t_data *data)
{
	static t_instr	check_instr[] = {
	{"sa\n", A, &swap}, {"sb\n", B, &swap}, {"ss\n", AB, &swap_both},
	{"pa\n", BA, &push}, {"pb\n", AB, &push}, {"ra\n", A, &rot},
	{"rb\n", B, &rot}, {"rr\n", AB, &rot_both}, {"rra\n", A, &rev_rot},
	{"rrb\n", B, &rev_rot}, {"rrr\n", AB, &rev_rot_both},
	};
	int				i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(arg, check_instr[i].cmp_str, ft_strlen(arg)))
		{
			if (check_instr[i].param == A)
				check_instr[i].ft_instr(&data->a);
			else if (check_instr[i].param == B)
				check_instr[i].ft_instr(&data->b);
			else if (check_instr[i].param == AB)
				check_instr[i].ft_instr(&data->a, &data->b);
			else if (check_instr[i].param == BA)
				check_instr[i].ft_instr(&data->b, &data->a);
			return (READABLE);
		}
	}
	return (NOT_READABLE);
}

static void	wait_instructions(t_data *data)
{
	char	*gnl_return;

	gnl_return = get_next_line(0);
	while (gnl_return != NULL)
	{
		if (check_instruction(gnl_return, data) == NOT_READABLE)
		{
			if (data->a)
				ft_lstclear(&data->a);
			if (data->b)
				ft_lstclear(&data->b);
			ft_error("Error\n");
		}
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
	init_list(&data, argv);
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
