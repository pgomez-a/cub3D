/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:49:21 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 12:34:41 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_color(int texY, char **color, t_data *dt)
{
	if (dt->map.side == 0 && dt->ray.dirX > 0)
	{
		texY = (int)dt->tex.texPos & (dt->eas.height - 1);
		(*color) = dt->eas.addr + (texY * dt->eas.length);
		(*color) += (dt->tex.texX * (dt->eas.bpp / 8));
	}
	else if (dt->map.side == 0 && dt->ray.dirX < 0)
	{
		texY = (int)dt->tex.texPos & (dt->wes.height - 1);
		(*color) = dt->wes.addr + (texY * dt->wes.length);
		(*color) += (dt->tex.texX * (dt->wes.bpp / 8));
	}
	else if (dt->map.side == 1 && dt->ray.dirY > 0)
	{
		texY = (int)dt->tex.texPos & (dt->sou.height - 1);
		(*color) = dt->sou.addr + (texY * dt->sou.length);
		(*color) += (dt->tex.texX * (dt->sou.bpp / 8));
	}
	else
	{
		texY = (int)dt->tex.texPos & (dt->nor.height - 1);
		(*color) = dt->nor.addr + (texY * dt->nor.length);
		(*color) += (dt->tex.texX * (dt->nor.bpp / 8));
	}
}

void	cb_buff_no_wall(int x, int **buffer, t_data *dt)
{
	int	count;

	count = 0;
	while (count < dt->screen_H)
	{
		if (count < dt->spr.startY)
			buffer[count][x] = dt->map.ceil;
		else if (count >= dt->spr.endY)
			buffer[count][x] = dt->map.floor;
		count++;
	}
}

void	cb_find_texX(t_data *dt)
{
	int	texPos;

	if (dt->map.side == 0)
		dt->tex.wallX = dt->ply.posY + dt->ray.wallDist * dt->ray.dirY;
	else
		dt->tex.wallX = dt->ply.posX + dt->ray.wallDist * dt->ray.dirX;
	dt->tex.wallX -= floor(dt->tex.wallX);
	if (dt->map.side == 0 && dt->ray.dirX >= 0)
	{
		texPos = (int)(dt->tex.wallX * (double)dt->eas.width);
		texPos = dt->eas.width - texPos - 1;
	}
	else if (dt->map.side == 0 && dt->ray.dirX < 0)
		texPos = (int)(dt->tex.wallX * (double)dt->wes.width);
	else if (dt->map.side == 1 && dt->ray.dirY >= 0)
		texPos = (int)(dt->tex.wallX * (double)dt->sou.width);
	else
	{
		texPos = (int)(dt->tex.wallX * (double)dt->nor.width);
		texPos = dt->nor.width - texPos - 1;
	}
	dt->tex.texX = texPos;
}

void	cb_find_texPos(t_data *dt)
{
	double	step;
	double	texPos;

	if (dt->map.side == 0 && dt->ray.dirX >= 0)
		step = 1.0 * dt->eas.height / dt->ray.lineH;
	else if (dt->map.side == 0 && dt->ray.dirX < 0)
		step = 1.0 * dt->wes.height / dt->ray.lineH;
	else if (dt->map.side == 1 && dt->ray.dirY >= 0)
		step = 1.0 * dt->sou.height / dt->ray.lineH;
	else
		step = 1.0 * dt->nor.height / dt->ray.lineH;
	texPos = (dt->spr.startY - dt->screen_H / 2 + dt->ray.lineH / 2) * step;
	dt->tex.step = step;
	dt->tex.texPos = texPos;
}

void	cb_buff_wall(int x, int **buffer, t_data *dt)
{
	char	*color;
	int		texY;
	int		y;

	y = dt->spr.startY;
	texY = 0;
	color = NULL;
	while (y < dt->spr.endY)
	{
		find_color(texY, &color, dt);
		buffer[y][x] = *(unsigned int *)color;
		dt->tex.texPos += dt->tex.step;
		y++;
	}
}
