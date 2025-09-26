/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:57:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# define PRINT_A 1
# define PRINT_B 2
# define NO_PRINT 0

/* push_swap instructions */
void	push_pile(t_list **from_pile, t_list **to_pile, int print);
void	swap_pile(t_list **pile, int print);
void	rotate_pile(t_list **pile, int print);
void	rotate_both(t_list **pile_a, t_list **pile_b);
void	reverse_rotate_pile(t_list **pile, int print);
void	reverse_rotate_both(t_list **pile_a, t_list **pile_b);

/* algorithm */
void	sort_big_pile(t_data *data);
void	sort_small_pile(t_list **pile_a, t_list **pile_b);
void	move_index_top(t_list **pile, int index, int print);
void	move_both_index_top(t_list **pile_a, t_list **pile_b, int worthiest);
void	reorder_small_pile(t_list **pile_a, int max);

#endif