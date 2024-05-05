/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:55:13 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 00:11:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	assign_sprites_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->down = load_sprites("./img/player/dir/down/down0.xpm", '4', game);
	txt->up = load_sprites("./img/player/dir/up/up0.xpm", '4', game);
	txt->left = load_sprites("./img/player/dir/left/left0.xpm", '4', game);
	txt->right = load_sprites("./img/player/dir/right/right0.xpm", '4', game);
	txt->current = game->textures.down;
	txt->current_back = game->textures.down;
	txt->dead.ptr = mlx_xpm_file_to_image(game->mlx, "./img/player/dead.xpm", \
		&txt->dead.width, &txt->dead.height);
	txt->mob = load_sprites("./img/mob/mob0.xpm", '8', game);
	txt->mob_back = game->textures.mob;
	txt->collectible = load_sprites("./img/collectible/coin0.xpm", '7', game);
	txt->collectible_back = game->textures.collectible;
}

static void	assign_environment_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->wall.ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/wall.xpm", &txt->wall.width, &txt->wall.height);
	txt->wall.addr = mlx_get_data_addr(txt->wall.ptr, &txt->wall.bpp, \
		&txt->wall.line_len, &txt->wall.endian);
	txt->floor[0].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground.xpm", &txt->floor[0].width, &txt->floor[0].height);
	txt->floor[0].addr = mlx_get_data_addr(txt->floor[0].ptr, &txt->floor[0].bpp, \
		&txt->floor[0].line_len, &txt->floor[0].endian);
	txt->floor[1].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground1.xpm", &txt->floor[1].width, &txt->floor[1].height);
	txt->floor[1].addr = mlx_get_data_addr(txt->floor[1].ptr, &txt->floor[1].bpp, \
		&txt->floor[1].line_len, &txt->floor[1].endian);
	txt->floor[2].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/ground2.xpm", &txt->floor[2].width, &txt->floor[2].height);
	txt->floor[2].addr = mlx_get_data_addr(txt->floor[2].ptr, &txt->floor[2].bpp, \
		&txt->floor[2].line_len, &txt->floor[2].endian);
	txt->exit[0].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/exit0.xpm", &txt->exit[0].width, &txt->exit[0].height);
	txt->exit[0].addr = mlx_get_data_addr(txt->exit[0].ptr, &txt->exit[0].bpp, \
		&txt->exit[0].line_len, &txt->exit[0].endian);
	txt->exit[1].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/env/exit1.xpm", &txt->exit[1].width, &txt->exit[1].height);
	txt->exit[1].addr = mlx_get_data_addr(txt->exit[1].ptr, &txt->exit[1].bpp, \
		&txt->exit[1].line_len, &txt->exit[1].endian);
	txt->border[0].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border.xpm", &txt->border[0].width, \
		&txt->border[0].height);
	txt->border[0].addr = mlx_get_data_addr(txt->border[0].ptr, &txt->border[0].bpp, \
		&txt->border[0].line_len, &txt->border[0].endian);
	txt->border[1].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border_go.xpm", &txt->border[1].width, \
		&txt->border[1].height);
	txt->border[1].addr = mlx_get_data_addr(txt->border[1].ptr, &txt->border[1].bpp, \
		&txt->border[1].line_len, &txt->border[1].endian);
	txt->border[2].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/border/border_lvl.xpm", &txt->border[2].width, \
		&txt->border[2].height);
	txt->border[2].addr = mlx_get_data_addr(txt->border[2].ptr, &txt->border[2].bpp, \
		&txt->border[2].line_len, &txt->border[2].endian);
}

static void	assign_numbers_textures(t_game *game)
{
	t_texture	*txt;

	txt = &game->textures;
	txt->number[0].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/0.xpm", &txt->number[0].width, &txt->number[0].height);
	txt->number[1].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/1.xpm", &txt->number[1].width, &txt->number[1].height);
	txt->number[2].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/2.xpm", &txt->number[2].width, &txt->number[2].height);
	txt->number[3].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/3.xpm", &txt->number[3].width, &txt->number[3].height);
	txt->number[4].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/4.xpm", &txt->number[4].width, &txt->number[4].height);
	txt->number[5].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/5.xpm", &txt->number[5].width, &txt->number[5].height);
	txt->number[6].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/6.xpm", &txt->number[6].width, &txt->number[6].height);
	txt->number[7].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/7.xpm", &txt->number[7].width, &txt->number[7].height);
	txt->number[8].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/8.xpm", &txt->number[8].width, &txt->number[8].height);
	txt->number[9].ptr = mlx_xpm_file_to_image(game->mlx, \
		"./img/numbers/9.xpm", &txt->number[9].width, &txt->number[9].height);
}

void	assign_textures(t_game *game)
{
	assign_sprites_textures(game);
	assign_environment_textures(game);
	assign_numbers_textures(game);
}
