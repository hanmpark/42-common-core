/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:40:36 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 00:01:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	render_elements(t_pos win, t_img *buffer, t_pos pl, t_game *g)
{
	if ((pl.x % 2 && !(pl.y % 2)) || (!(pl.x % 2) && pl.y % 2))
		put_image_to_buffer(g, buffer, g->textures.floor[0], win.x, win.y);
	else
		put_image_to_buffer(g, buffer, g->textures.floor[1], win.x, win.y);
	if (g->map[pl.y][pl.x] == 'C' || g->map[pl.y][pl.x] == 'T')
		put_image_to_buffer(g, buffer, g->textures.collectible->img, \
			win.x, win.y);
	else if (pl.x == g->content.exit_pos.x && \
		pl.y == g->content.exit_pos.y)
		put_image_to_buffer(g, buffer, g->textures.current_exit, win.x, win.y);
	else if (g->map[pl.y][pl.x] == '1')
		put_image_to_buffer(g, buffer, g->textures.wall, win.x, win.y);
}

static void	render_map(t_game *game, t_img *buffer, t_pos pl)
{
	int		og;
	t_pos	win;

	og = pl.x;
	win.y = -1;
	while (++win.y < 9)
	{
		win.x = -1;
		pl.x = og;
		while (++win.x < 13)
		{
			if (pl.x < 0 || pl.x >= game->size.x || \
				pl.y < 0 || pl.y >= game->size.y)
			{
				put_image_to_buffer(game, buffer, game->textures.floor[2], \
					win.x, win.y);
				put_image_to_buffer(game, buffer, game->textures.wall, \
					win.x, win.y);
			}
			if ((pl.x >= 0 && pl.x < game->size.x) && \
				(pl.y >= 0 && pl.y < game->size.y))
				render_elements(win, buffer, pl, game);
			pl.x++;
		}
		pl.y++;
	}
}

static void	render_moves_count(t_game *game, t_img *buffer, int number)
{
	int	i;
	int	unit;

	i = -1;
	while (++i < 4)
	{
		unit = number % 10;
		put_image_to_buffer(game, buffer, game->textures.number[unit], \
			454 - ((game->textures.number->width + 8) * i), 593);
		number /= 10;
	}
}

static void	render_mob(t_game *g, t_img *buffer, int enemy_number)
{
	int		number;
	t_pos	pos;

	number = -1;
	while (++number < enemy_number)
	{
		pos.x = g->mobs[number].pos.x - (g->player.x - 6);
		pos.y = g->mobs[number].pos.y - (g->player.y - 4);
		if ((pos.x >= 0 && pos.x <= 12) && (pos.y >= 0 && pos.y <= 8))
			put_image_to_buffer(g, buffer, g->textures.mob->img, \
				64 * pos.x + (g->move_pl_px.x + g->mobs[number].move_px), \
				64 * pos.y + g->move_pl_px.y);
	}
}

int	render(t_game *game)
{
	t_pos	pl;
	t_img	buffer;

	buffer.ptr = mlx_new_image(game->mlx, 832, 704);
	buffer.addr = mlx_get_data_addr(buffer.ptr, &buffer.bpp, \
		&buffer.line_len, &buffer.endian);
	buffer.width = 832;
	buffer.height = 704;
	pl.y = game->player.y - 4;
	pl.x = game->player.x - 6;
	render_map(game, &buffer, pl);
	if (game->state == GAME_ON || game->state == GAME_WIN)
		put_image_to_buffer(game, &buffer, game->textures.current->img, \
			6 * 64, 4 * 64);
	else
		put_image_to_buffer(game, &buffer, game->textures.dead, \
			6 * 64, 4 * 64);
	render_mob(game, &buffer, game->content.count_mob);
	put_image_to_buffer(game, &buffer, game->textures.exit[game->state], 0, 0);
	render_moves_count(game, &buffer, game->count_moves);
	mlx_put_image_to_window(game->mlx, game->win, buffer.ptr, 0, 0);
	return (0);
}
