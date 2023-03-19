/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/19 12:48:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_BONUS_H
# define INSTRUCTIONS_BONUS_H

# define PRINT_A 1
# define PRINT_B 2
# define NO_PRINT 0

/* push_swap instructions */
void	push(t_list **from_pile, t_list **to_pile);
void	swap(t_list **pile);
void	swap_both(t_list **pile_a, t_list **pile_b);
void	rot(t_list **pile);
void	rot_both(t_list **pile_a, t_list **pile_b);
void	rev_rot(t_list **pile);
void	rev_rot_both(t_list **pile_a, t_list **pile_b);

#endif