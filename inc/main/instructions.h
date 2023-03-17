/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 16:24:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# define PRINT_A 1
# define PRINT_B 2
# define NO_PRINT 0

/* push_swap instructions */
void	push_list(t_list **from_list, t_list **to_list, int print);
void	swap_list(t_list **list, int print);
void	rotate_list(t_list **list, int print);
void	rotate_both(t_list **list_a, t_list **list_b);
void	reverse_rotate_list(t_list **list, int print);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);

/* algorithm */
void	sort_big_list(t_data *data);
void	sort_small_list(t_list **list_a, t_list **list_b);
void	move_index_top(t_list **list, int index, int print);
void	move_both_index_top(t_list **list_a, t_list **list_b, int worthiest);
void	reorder_small_list(t_list **list_a, int max);

#endif