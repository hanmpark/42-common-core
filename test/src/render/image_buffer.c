/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:45:02 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 00:05:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	put_pixel(t_img *buffer, int x, int y, unsigned int color)
{
	char	*dst;

	ft_printf("buffer->width = %d and buffer->height = %d\n", buffer->width, buffer->height);
	ft_printf("color = %u\n", color);
	if (color == 0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < buffer->width && y < buffer->height)
	{
		dst = buffer->addr + (y * buffer->line_len + x * (buffer->bpp / 8));
		*(unsigned int *)dst = color;
		ft_printf("OK\n");
	}
}

static unsigned int	get_pixel(t_img img, int x, int y)
{
	return (*(unsigned int *) \
		((img.addr + (y * img.line_len) + x * (img.bpp / 8))));
}

void	put_image_to_buffer(t_game *game, t_img *buffer, t_img img, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("img.width = %d and img.height = %d\n", img.width, img.height);
	while (++i < img.width)
	{
		j = -1;
		while (++j < img.height)
			put_pixel(buffer, 64 * x + game->move_pl_px.x + j, \
				64 * y + game->move_pl_px.y + i, get_pixel(img, j, i));
	}
}
