/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:30:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/05 23:06:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "hooks.h"

int	game_close(t_game *game)
{
	if (game->map)
		ft_freetab(game->map);
	free(game->mobs);
	clear_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

static void	dir_pressed(t_sprite *sprites, t_game *game, int *dir)
{
	if (*dir == 0)
	{
		*dir = 1;
		game->textures.current = sprites;
		game->textures.current_back = sprites;
	}
}

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
		game_close(game);
	else if (key == KEY_L && game->state == GAME_ON)
		dir_pressed(game->textures.left, game, &game->hook.dir.left);
	else if (key == KEY_R && game->state == GAME_ON)
		dir_pressed(game->textures.right, game, &game->hook.dir.right);
	else if (key == KEY_D && game->state == GAME_ON)
		dir_pressed(game->textures.down, game, &game->hook.dir.down);
	else if (key == KEY_U && game->state == GAME_ON)
		dir_pressed(game->textures.up, game, &game->hook.dir.up);
	return (0);
}

int	key_released(int key, t_game *game)
{
	if (key == KEY_L && game->state == GAME_ON)
		game->hook.dir.left = 0;
	else if (key == KEY_R && game->state == GAME_ON)
		game->hook.dir.right = 0;
	else if (key == KEY_D && game->state == GAME_ON)
		game->hook.dir.down = 0;
	else if (key == KEY_U && game->state == GAME_ON)
		game->hook.dir.up = 0;
	return (0);
}
