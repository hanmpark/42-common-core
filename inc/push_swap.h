/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/09 15:45:21 by hanmpark         ###   ########.fr       */
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

# define UPPER_HALF 1
# define BOTTOM_HALF 0

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

void	init_list_a(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);

void	sort_list(t_data *data);
void	push_a(t_list **list_b, t_list **list_a);
void	push_b(t_list **list_a, t_list **list_b);
void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	swap_both(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **list_a);
void	rotate_b(t_list **list_b);
void	rotate_both(t_list **list_a, t_list **list_b);
void	reverse_rotate_a(t_list **list_a);
void	reverse_rotate_b(t_list **list_b);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);

#endif