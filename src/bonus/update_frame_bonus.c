/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:20:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/04/03 16:07:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "move_bonus.h"

static void	anim_player(t_data *game)
{
	if ((game->hook.anim.left || game->hook.anim.right || \
		game->hook.anim.down || game->hook.anim.up) && !(game->frames % 7))
		game->img.current = game->img.current->next;
	if (!game->img.current || (!game->hook.is_anim && !game->hook.dir.left && \
		!game->hook.dir.right && !game->hook.dir.down && !game->hook.dir.up))
		game->img.current = game->img.current_back;
}

static void	anim_enemy(t_data *game)
{
	if (!(game->frames % 5))
		game->img.mob = game->img.mob->next;
	if (!game->img.mob)
		game->img.mob = game->img.mob_back;
	if (!(game->frames % 100))
		game->move_enemy = 1;
}

static void	anim_collectible(t_data *game)
{
	if (!(game->frames % 5))
		game->img.collectible = game->img.collectible->next;
	if (!game->img.collectible)
		game->img.collectible = game->img.collectible_back;
}

int	update(t_data *game)
{
	game->frames++;
	if (game->frames < 0)
		game->frames = 0;
	check_game(game, game->player, game->enemy);
	anim_collectible(game);
	anim_enemy(game);
	if (game->game_state == GAME_ON)
		anim_player(game);
	if (game->move_enemy)
		move_enemy(game);
	move_player(game);
	render(game);
	return (0);
}
