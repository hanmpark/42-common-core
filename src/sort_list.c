/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/08 10:21:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_list(t_data *data)
{
	rotate_a(&data->a);
	push_b(&data->a, &data->b);
	push_b(&data->a, &data->b);
	push_b(&data->a, &data->b);
	rotate_both(&data->a, &data->b);
}
