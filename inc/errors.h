/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:54:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/29 14:11:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS "Error\nWrong number of arguments\n"
# define ERR_PIPE "Error\nProblem occurred with pipe()\n"
# define ERR_FORK "Error\nProblem occurred with fork()\n"
# define ERR_MALLOC "Error\nProblem occurred with malloc()\n"
# define ERR_OPEN "Error\nProblem occurred with open()\n"
# define ERR_EXEC "Error\nProblem occurred with execve()\n"
# define ERR_PATH "Error\nenvPath not found\n"
# define ERR_CMDPATH "Error\nCommand does not exist / not accessible\n"

#endif