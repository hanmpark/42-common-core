/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:54:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/30 11:09:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <sys/errno.h>

# define ERR_ARGS "main()"
# define ERR_PIPE "pipe()"
# define ERR_FORK "fork()"
# define ERR_MALLOC "malloc()"
# define ERR_OPEN "open()"
# define ERR_EXEC "execve()"
# define ERR_PATH "definePath()"
# define ERR_CMDPATH "defineCommand()"

#endif