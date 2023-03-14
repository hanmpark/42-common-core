/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 14:41:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATE_H
# define LOCATE_H

# define UPPER_HALF 1
# define BOTTOM_HALF 0

void	count_moves(t_list **list_a, t_list **list_b);
int		half_locate(t_list **list, int index);
int		worthiest_index(t_list **list_b);
int		strict_superior_index(t_list **list, int index);
int		smallest_index(t_list **list);

#endif