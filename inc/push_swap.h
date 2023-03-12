/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/12 12:48:42 by hanmpark         ###   ########.fr       */
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

# define PRINT_A 1
# define PRINT_B 2
# define NO_PRINT 0

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	int		max_value;
}	t_data;

void	init_list_a(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);

void	push_to_b(int max_value, t_list **list_a, t_list **list_b);

void	push_list(t_list **from_list, t_list **to_list, int print);

void	swap_list(t_list **list, int print);
void	swap_both(t_list **list_a, t_list **list_b);

void	rotate_list(t_list **list, int print);
void	rotate_both(t_list **list_a, t_list **list_b);

void	reverse_rotate_list(t_list **list, int print);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);

void	count_moves(t_list **list_a, t_list **list_b);
void	pick_list(t_list **list_a, t_list **list_b);
int		list_location(t_list **list, int index);
int		index_to_move(t_list **b);
int		ascending_index(t_list **list, int index);

void	move_index_top(t_list **list, int index, int print);
void	move_index_bottom(t_list **list, int index, int print);
void	move_index_ascending(t_list **list, int index, int print);

/* PRINTING A LIST TO SEE ITS STATE */
void	print_list(t_list *list, int print);

#endif