/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:44:38 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 12:13:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_path(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	check_game(t_game *game, t_pos pl, t_mob *mob)
{
	int	len;

	len = 0;
	while (len < game->content.count_mob)
	{
		if (game->state == GAME_ON && \
			(pl.x == mob[len].pos.x) && (pl.y == mob[len].pos.y))
		{
			ft_printf("%sGAME OVER\nYou got killed by a slime !%s\n", \
				RED, DEF);
			game->textures.current = game->textures.dead.ptr;
			game->textures.current_back = game->textures.dead.ptr;
			game->state = GAME_OVER;
		}
		len++;
	}
}

static void	check_case(int x, int y, t_game *game)
{
	static int	collectible = 0;
	t_pos		exit;

	exit = game->content.exit_pos;
	if (exit.x == x && exit.y == y && game->exit)
	{
		ft_printf("%sGAME SUCCESS\nLevel completed in %d moves !%s\n", \
			GREEN, game->count_moves, DEF);
		game->state = GAME_WIN;
	}
	else if (game->map[y][x] == 'C')
	{
		collectible++;
		game->map[y][x] = '0';
		if (collectible == game->content.collectible)
		{
			game->textures.current_exit = game->textures.exit[1];
			game->exit = 1;
		}
	}
}

void	move_dir(int x, int y, t_game *game)
{
	game->count_moves++;
	ft_printf("Moves : %d\n", game->count_moves);
	check_case(x, y, game);
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}
