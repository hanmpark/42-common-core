/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 14:53:58 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# define PRINT_A 1
# define PRINT_B 2
# define NO_PRINT 0

/* push_swap instructions */
void	push(t_list **from_list, t_list **to_list);
void	swap(t_list **list);
void	swap_both(t_list **list_a, t_list **list_b);
void	rot(t_list **list);
void	rot_both(t_list **list_a, t_list **list_b);
void	rev_rot(t_list **list);
void	rev_rot_both(t_list **list_a, t_list **list_b);

#endif