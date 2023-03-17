/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:24:39 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 15:47:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

# define NOT_READABLE 0
# define READABLE 1

# define A 1
# define B 2
# define AB 3
# define BA 4

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	int		max_value;
}	t_data;

typedef void	(*t_ft_instr)();

typedef struct	s_instr
{
	const char	*cmp_str;
	int			param;
	t_ft_instr	ft_instr;
}	t_instr;

#endif