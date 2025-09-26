/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:22:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 12:10:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# include <sys/errno.h>

# define ERR_ARGS "stdin"
# define ERR_PIPE "pipe()"
# define ERR_FORK "fork()"
# define ERR_MALLOC "malloc()"
# define ERR_OPEN "open()"
# define ERR_EXEC "execve()"
# define ERR_PATH "definePath()"
# define ERR_CMDPATH "checkCommand()"

#endif