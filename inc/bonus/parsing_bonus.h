/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:31:50 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/17 13:20:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# define TRUE 1
# define FALSE 0

# define ERR "Error\n"

void	init_list(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);
int		check_int(char *nbr);
void	check_duplicate(t_list *list_a);

#endif