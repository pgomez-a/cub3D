/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_renderframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:35:51 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 14:04:49 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ray(int x, t_data *dt)
{
	double	camX;

	camX = 2 * x / (double)dt->screen_W - 1;
	dt->ray.dirX = dt->ply.dirX + dt->ply.plnX * camX;
	dt->ray.dirY = dt->ply.dirY + dt->ply.plnY * camX;
	dt->ray.ddistX = fabs(1 / dt->ray.dirX);
	dt->ray.ddistY = fabs(1 / dt->ray.dirY);
}

static void	dist_to_wall(t_data *dt)
{
	dt->map.x = (int)dt->ply.posX;
	dt->map.y = (int)dt->ply.posY;
	if (dt->ray.dirX < 0)
	{
		dt->ray.stepX = -1;
		dt->ray.sdistX = (dt->ply.posX - dt->map.x) * dt->ray.ddistX;
	}
	else
	{
		dt->ray.stepX = 1;
		dt->ray.sdistX = (dt->map.x + 1.0 - dt->ply.posX) * dt->ray.ddistX;
	}
	if (dt->ray.dirY < 0)
	{
		dt->ray.stepY = -1;
		dt->ray.sdistY = (dt->ply.posY - dt->map.y) * dt->ray.ddistY;
	}
	else
	{
		dt->ray.stepY = 1;
		dt->ray.sdistY = (dt->map.y + 1.0 - dt->ply.posY) * dt->ray.ddistY;
	}
}

static void	dda_algorithm(t_data *dt)
{
	int	 hit;

	hit = 0;
	while (hit == 0)
	{
		if (dt->ray.sdistX < dt->ray.sdistY)
		{
			dt->ray.sdistX += dt->ray.ddistX;
			dt->map.x += dt->ray.stepX;
			dt->map.side = 0;
		}
		else
		{
			dt->ray.sdistY += dt->ray.ddistY;
			dt->map.y += dt->ray.stepY;
			dt->map.side = 1;
		}
		if (dt->map.world[dt->map.y][dt->map.x] == '1')
			hit = 1;
	}
}

static void	find_height_line(int **buffer, int x, t_data *dt)
{
	if (dt->map.side == 0)
	{
		dt->ray.wallDist = (dt->map.x - dt->ply.posX + (1 - dt->ray.stepX) / 2);
		dt->ray.wallDist /= dt->ray.dirX;
	}
	else
	{
		dt->ray.wallDist = (dt->map.y - dt->ply.posY + (1 - dt->ray.stepY) / 2);
		dt->ray.wallDist /= dt->ray.dirY;
	}
	dt->ray.lineH = (int)(dt->screen_H / dt->ray.wallDist);
	dt->spr.startY = dt->screen_H / 2 - dt->ray.lineH / 2;
	if (dt->spr.startY < 0)
		(dt->spr.startY) = 0;
	dt->spr.endY = dt->screen_H / 2 + dt->ray.lineH / 2;
	if (dt->spr.endY >= dt->screen_H)
		dt->spr.endY = dt->screen_H - 1;
	cb_buff_no_wall(x, buffer, dt);
	cb_find_texX(dt);
	cb_find_texPos(dt);
	cb_buff_wall(x, buffer, dt);
}

int	cb_render_frame(t_data *dt)
{
	int	x;
	int	**buffer;

	cb_init_buffer(1, &buffer, dt);
	cb_change_values(dt);
	x = 0;
	while (x < dt->screen_W)
	{
		set_ray(x, dt);
		dist_to_wall(dt);
		dda_algorithm(dt);
		find_height_line(buffer, x, dt);
		dt->spr.zbuf[x] = dt->ray.wallDist;
		x++;
	}
	cb_sprites(buffer, dt);
	cb_draw_buffer(buffer, dt);
	cb_init_buffer(0, &buffer, dt);
	mlx_put_image_to_window(dt->mlx.mlx, dt->mlx.win, dt->mlx.img, 0, 0);
	mlx_do_sync(dt->mlx.mlx);
	return (0);
}
