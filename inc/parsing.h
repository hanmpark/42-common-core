/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:21:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 20:24:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define TRUE 1
# define FALSE 0

# define ERR_INT "Error\nParameter(s) is/are not int\n"
# define ERR_DUP "Error\nThere is/are duplicate(s) in parameter(s)\n"

void	init_list(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);

#endif