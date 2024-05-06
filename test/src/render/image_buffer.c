/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:45:02 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/06 09:59:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	put_pixel(t_img *buffer, int x, int y, unsigned int color)
{
	char	*dst;

	if (color == 0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < buffer->width && y < buffer->height)
	{
		dst = buffer->addr + (y * buffer->line_len + x * (buffer->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static unsigned int	get_pixel(t_img img, int x, int y)
{
	unsigned int const	offset = y * img.line_len + x * (img.bpp / 8);

	return (*(unsigned int *)(img.addr + offset));
}

void	put_image_to_buffer(t_img *buffer, t_img img, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img.height)
	{
		j = -1;
		while (++j < img.width)
			put_pixel(buffer, x + j, y + i, get_pixel(img, j, i));
	}
}
