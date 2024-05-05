/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:51:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/05 23:45:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "hooks.h"

static void	new_window(t_game *game, int x, int y)
{
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	render(game);
}

static void	data_init(t_game *game)
{
	game->move_pl_px.x = 0;
	game->move_pl_px.y = 0;
	game->hook.dir.left = 0;
	game->hook.dir.right = 0;
	game->hook.dir.up = 0;
	game->hook.dir.down = 0;
	game->hook.anim.left = 0;
	game->hook.anim.right = 0;
	game->hook.anim.up = 0;
	game->hook.anim.down = 0;
	game->hook.is_anim = 0;
	game->frames = 0;
	game->exit = 0;
	game->count_moves = 0;
	game->move_enemy = STILL_ENEMY;
	game->state = GAME_ON;
	game->textures.current_exit = game->textures.exit[0];
}

bool	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (send_error(game->map, game->mobs, ERR_MLX));
	assign_textures(game);
	data_init(game);
	new_window(game, 832, 704);
	mlx_hook(game->win, KEYPRESS, KEY_MASK, &game_close, game);
	mlx_hook(game->win, KEYRELEASE, KEY_MASK, &key_released, game);
	// mlx_loop_hook(game->mlx, &update, game);
	mlx_loop(game->mlx);
	return (true);
}
