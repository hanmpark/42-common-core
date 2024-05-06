/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:20:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/05 23:10:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

static bool	filling(int x, int y, char **draftmap, t_game *g)
{
	static int	collectible = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= g->size.x || y >= g->size.y)
		return (false);
	if (draftmap[y][x] == 'F' || draftmap[y][x] == '1' || \
		draftmap[y][x] == 'M')
		return (false);
	else if (draftmap[y][x] == 'C')
		collectible++;
	else if (draftmap[y][x] == 'E')
		exit++;
	draftmap[y][x] = 'F';
	filling(x - 1, y, draftmap, g);
	filling(x + 1, y, draftmap, g);
	filling(x, y - 1, draftmap, g);
	filling(x, y + 1, draftmap, g);
	if (collectible != g->content.collectible || !exit)
		return (false);
	return (true);
}

bool	flood_fill(t_game *game, char **tmpmap)
{
	if (!filling(game->player.x, game->player.y, tmpmap, game))
	{
		ft_freetab(tmpmap);
		return (false);
	}
	ft_freetab(tmpmap);
	return (true);
}
