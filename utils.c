/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:20:08 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/29 09:01:58 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->mlx.addr + (y * dt->mlx.length) + (x * (dt->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

void	cb_init_buffer(int mode, int ***buffer, t_data *dt)
{
	int	x;

	if (mode == 1)
	{
		x = 0;
		(*buffer) = (int **)malloc(sizeof(int *) * dt->screen_H);
		while (x < dt->screen_H)
		{
			(*buffer)[x] = (int *)malloc(sizeof(int) * dt->screen_W);
			x++;
		}
	}
	else if (mode == 0)
	{
		x = 0;
		while (x < dt->screen_H)
			free((*buffer)[x++]);
		free(*buffer);
	}
}

void	cb_draw_buffer(int **buffer, t_data *dt)
{
	int	count_y;
	int	count_x;

	count_y = 0;
	while (count_y < dt->screen_H)
	{
		count_x = 0;
		while (count_x < dt->screen_W)
		{
			my_mlx_pixel_put(dt, count_x, count_y, buffer[count_y][count_x]);
			count_x++;
		}
		count_y++;
	}
}

static int	calculate_tex_cor(int mode, int cor, int size, t_data *dt)
{
	int	result;

	if (mode == 0)
	{
		result = (int)((cor - (-size / 2 + dt->spr.screenX))
				* dt->spr.width / size);
		return (result);
	}
	else if (mode == 1)
	{
		result = cor * 256 - dt->screen_H * 128 + size * 128;
		result = ((result * dt->spr.height) / size) / 256;
		return (result);
	}
	return (-1);
}

void	cb_draw_sprites(int width, int height, int **buffer, t_data *dt)
{
	char	*color;
	int		stripe;
	int		texX;
	int		texY;
	int		y;

	stripe = dt->spr.startX;
	while (stripe < dt->spr.endX)
	{
		texX = calculate_tex_cor(0, stripe, width, dt);
		if (dt->spr.dirY > 0 && stripe > 0 && stripe < dt->screen_W
			&& dt->spr.dirY < dt->spr.zbuf[stripe])
		{
			y = dt->spr.startY;
			while (y < dt->spr.endY)
			{
				texY = calculate_tex_cor(1, y, height, dt);
				color = dt->spr.addr + (texY * dt->spr.length);
				color += (texX * (dt->spr.bpp / 8));
				if (y++ && (*(unsigned int *)color & 0x00FFFFFF) != 0)
					buffer[y - 1][stripe] = *(unsigned int *)color;
			}
		}
		stripe++;
	}
}
