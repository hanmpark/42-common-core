/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:32:35 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/05 23:08:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

# define ERR_MLX "Error: mlx failed to initialize\n"

typedef enum e_state
{
	GAME_ON,
	GAME_OVER,
	GAME_WIN
}	t_state;

typedef enum e_movement
{
	MOVE_ENEMY,
	STILL_ENEMY,
	LEFT,
	RIGHT,
	STATIC
}	t_movement;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sprite
{
	t_img			img;
	struct s_sprite	*next;
}	t_sprite;

typedef struct s_texture
{
	t_sprite	*left;
	t_sprite	*right;
	t_sprite	*down;
	t_sprite	*up;
	t_sprite	*current;
	t_sprite	*current_back;
	t_sprite	*mob;
	t_sprite	*mob_back;
	t_sprite	*collectible;
	t_sprite	*collectible_back;
	t_img		dead;
	t_img		current_exit;
	t_img		floor[3];
	t_img		exit[2];
	t_img		number[10];
	t_img		wall;
	t_img		border[3];
}	t_texture;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_content
{
	int		is_player;
	int		collectible;
	int		exit;
	t_pos	exit_pos;
	int		count_mob;
}	t_cnt;

typedef struct s_dir
{
	int	left;
	int	right;
	int	up;
	int	down;
}	t_dir;

typedef struct s_mob
{
	t_pos		pos;
	int			move_px;
	t_movement	dir;
}	t_mob;

typedef struct s_hook
{
	t_dir	dir;
	t_dir	anim;
	int		is_anim;
}	t_hook;

typedef struct s_game
{
	char		**map;
	t_cnt		content;
	t_pos		size;
	t_pos		player;
	t_pos		move_pl_px;
	int			exit;
	int			count_moves;
	void		*mlx;
	void		*win;
	t_mob		*mobs;
	t_texture	textures;
	t_hook		hook;
	int			frames;
	int			move_enemy;
	t_state		state;
}	t_game;

bool	send_error(char **map, void *data, char *str);
bool	game_init(t_game *game);

void	put_image_to_buffer(t_game *game, t_img *buffer, t_img img, int x, int y);

// Textures
t_sprite	*newsprite(t_game *game, char *path);
t_sprite	*lastsprite(t_sprite *sprite);
void		addsprite(t_sprite **sprite, t_sprite *new);
t_sprite	*load_sprites(char *path, char c, t_game *game);
t_img		get_img(void *mlx_ptr, char *path, int *width, int *height);

void		assign_textures(t_game *game);
void		clear_textures(t_game *g);

int			render(t_game *game);

// Hooks
int			key_pressed(int key, t_game *game);
int			key_released(int key, t_game *game);
int			game_close(t_game *game);

#endif
