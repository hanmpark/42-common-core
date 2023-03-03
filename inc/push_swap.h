/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/03 09:30:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

void	init_list_a(t_data *data, int length, char **integers);

#endif