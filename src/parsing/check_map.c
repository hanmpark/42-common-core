/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:06:00 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 14:00:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

static bool	check_edges(char **map, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->size.x)
		if (map[0][i] != '1' || map[game->size.y - 1][i] != '1')
			return (send_error(map, NULL, ERR_WALLS));
	i = -1;
	while (++i < game->size.y)
		if (map[i][0] != '1' || map[i][game->size.x - 1] != '1')
			return (send_error(map, NULL, ERR_WALLS));
	return (true);
}

static void	set_pos_and_increment(t_pos *pos, int x, int y, int *inc)
{
	pos->x = x;
	pos->y = y;
	(*inc)++;
}

static bool	check_case(char c, int x, int y, t_game *game)
{
	if (c == 'P' && !game->content.is_player)
		set_pos_and_increment(&game->player, x, y, &game->content.is_player);
	else if (c == 'P' && game->content.is_player)
		return (false);
	else if (c == 'C')
		game->content.collectible++;
	else if (c == 'E')
		set_pos_and_increment(&game->content.exit_pos, x, y, \
			&game->content.exit);
	else if (c == 'M')
		game->content.count_mob++;
	else if (c != '1' && c != '0')
		return (false);
	return (true);
}

static bool	check_content(char **map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (!check_case(map[y][x], x, y, game))
				return (send_error(map, NULL, ERR_CASE));
	}
	if (!game->content.collectible || game->content.exit != 1 || \
		game->content.is_player != 1)
		return (send_error(map, NULL, ERR_ELEMENTS));
	else if (!flood_fill(game, ft_mapdup(map)))
		return (send_error(map, NULL, ERR_IMPOSSIBLE));
	return (true);
}

bool	check_map(char **map, t_game *game)
{
	char	*tmp;
	int		i;

	game->size.x = (int)ft_strlen(map[0]) - 1;
	i = -1;
	while (map[++i])
	{
		tmp = ft_strtrim(map[i], "\n");
		free(map[i]);
		map[i] = tmp;
		if ((int)ft_strlen(map[i]) != game->size.x)
			return (send_error(map, NULL, ERR_BER));
	}
	return (check_edges(map, game) && check_content(map, game));
}
