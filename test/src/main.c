/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:32:12 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/05 23:05:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		send_error(NULL, NULL, ERR_BER);
		return (1);
	}
	if (!map_init(argv[1], &game))
		return (2);
	else if (!game_init(&game))
		return (3);
	return (0);
}
