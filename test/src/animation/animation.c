/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:27:28 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 14:11:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	anim_player(t_game *game)
{
	if ((game->hook.anim.left || game->hook.anim.right || \
		game->hook.anim.down || game->hook.anim.up) && !(game->frames % 3))
		game->textures.current = game->textures.current->next;
	if (!game->textures.current || (!game->hook.is_anim && !game->hook.dir.left \
		&& !game->hook.dir.right && !game->hook.dir.down && !game->hook.dir.up))
		game->textures.current = game->textures.current_back;
}

void	anim_enemy(t_game *game)
{
	if (!(game->frames % 3))
		game->textures.mob = game->textures.mob->next;
	if (!game->textures.mob)
		game->textures.mob = game->textures.mob_back;
	if (!(game->frames % 100))
		game->move_enemy = 1;
}

void	anim_collectible(t_game *game)
{
	if (!(game->frames % 5))
		game->textures.collectible = game->textures.collectible->next;
	if (!game->textures.collectible)
		game->textures.collectible = game->textures.collectible_back;
}
