/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/04 14:48:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define TRUE 1
# define FALSE 0

# define ERR_INT "Error\nParameter(s) is/are not int\n"
# define ERR_DUP "Error\nThere is/are duplicate(s) in parameter(s)\n"

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

void	init_list_a(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);

#endif