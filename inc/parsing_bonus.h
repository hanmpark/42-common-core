/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:31:50 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 15:51:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# define TRUE 1
# define FALSE 0

# define ERR "Error\n"

void	init_list_bonus(t_data *data, char **integers);
void	set_index_bonus(int length, t_list *list_a);
int		check_int_bonus(char *nbr);
void	check_duplicate_bonus(t_list *list_a);

#endif