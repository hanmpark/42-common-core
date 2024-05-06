/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:40:07 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 11:41:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_enemy_letter(int dir, t_mob *en, t_game *game)
{
	if (game->map[en->pos.y][en->pos.x] == 'T' || \
		game->map[en->pos.y][en->pos.x] == 'C')
		game->map[en->pos.y][en->pos.x] = 'C';
	else
		game->map[en->pos.y][en->pos.x] = '0';
	if (dir == LEFT)
	{
		if (game->map[en->pos.y][en->pos.x - 1] == 'C' || \
			game->map[en->pos.y][en->pos.x - 1] == 'T')
			game->map[en->pos.y][en->pos.x - 1] = 'T';
		else
			game->map[en->pos.y][en->pos.x - 1] = 'M';
	}
	else if (dir == RIGHT)
	{
		if (game->map[en->pos.y][en->pos.x + 1] == 'C' || \
			game->map[en->pos.y][en->pos.x + 1] == 'T')
			game->map[en->pos.y][en->pos.x + 1] = 'T';
		else
			game->map[en->pos.y][en->pos.x + 1] = 'M';
	}
}

static void	move_enemy_px(t_mob *en, t_game *game, int pixel, int dir)
{
	en->move_px += pixel;
	if (en->move_px == 64 || en->move_px == -64)
	{
		en->move_px = 0;
		game->move_enemy = 0;
		if (dir == LEFT)
		{
			set_enemy_letter(LEFT, en, game);
			en->pos.x -= 1;
			if (!check_path(game, en->pos.x - 1, en->pos.y))
				en->dir = RIGHT;
		}
		else if (dir == RIGHT)
		{
			set_enemy_letter(RIGHT, en, game);
			en->pos.x += 1;
			if (!check_path(game, en->pos.x + 1, en->pos.y))
				en->dir = LEFT;
		}
	}
}

void	move_enemy(t_game *game)
{
	t_mob	*en;
	int		i;

	en = game->mobs;
	i = 0;
	while (i < game->content.count_mob)
	{
		if (en[i].dir == LEFT)
			move_enemy_px(&en[i], game, -2, LEFT);
		else if (en[i].dir == RIGHT)
			move_enemy_px(&en[i], game, 2, RIGHT);
		i++;
	}
}
