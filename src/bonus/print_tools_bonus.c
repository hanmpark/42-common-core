/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:56:22 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 21:30:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	print_img(t_data *game, void *img, int x, int y)
{
	int	img_widht;
	int	img_height;
	int	*img_data;

	img_data = mlx_get_data_addr(img, &img_width,)
	mlx_put_image_to_window(game->mlx, game->win, img, \
		64 * x + game->move_pl_px.x, 64 * y + game->move_pl_px.y);
}

void	print_img_mob(t_data *g, int enemy_number)
{
	int		number;
	t_pos	pos;

	number = 0;
	while (number < enemy_number)
	{
		pos.x = g->enemy[number].pos.x - (g->player.x - 6);
		pos.y = g->enemy[number].pos.y - (g->player.y - 4);
		if ((pos.x >= 0 && pos.x <= 12) && (pos.y >= 0 && pos.y <= 8))
			mlx_put_image_to_window(g->mlx, g->win, g->img.mob->content, \
				64 * pos.x + (g->move_pl_px.x + g->enemy[number].move_px), \
				64 * pos.y + (g->move_pl_px.y));
		number++;
	}
}
