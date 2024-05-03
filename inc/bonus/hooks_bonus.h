/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:53:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 20:48:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# ifdef __APPLE__
#  define KEY_ESC		53
#  define KEY_L			0
#  define KEY_D			1
#  define KEY_R			2
#  define KEY_U			13
#  define KEY_SPACE		49
# elif defined __unix__
#  define KEY_ESC		65307
#  define KEY_L			97
#  define KEY_D			115
#  define KEY_R			100
#  define KEY_U			119
#  define KEY_SPACE		32
# endif

# define KEYPRESS 2
# define KEYRELEASE 3

int	key_released(int key, t_data *game);
int	key_pressed(int key, t_data *game);
int	game_close(t_data *game);

#endif