/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:33:01 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/29 08:43:00 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_sprites_dist(t_data *dt)
{
	int	y;

	y = 0;
	while (y < dt->spr.tot)
	{
		dt->spr.order[y] = (double)y;
		dt->spr.dist[y] = pow(dt->ply.posX - dt->spr.buf[y][1], 2);
		dt->spr.dist[y] += pow(dt->ply.posY - dt->spr.buf[y][0], 2);
		y++;
	}
	cb_sort_sprites(dt->spr.order, dt->spr.dist, dt->spr.tot);
}

static void	get_sprite_values(int y, t_data *dt)
{
	double	invMatrix;

	dt->spr.posX = dt->spr.buf[(int)dt->spr.order[y]][1] - dt->ply.posX;
	dt->spr.posY = dt->spr.buf[(int)dt->spr.order[y]][0] - dt->ply.posY;
	invMatrix = 1 / (dt->ply.plnX * dt->ply.dirY - dt->ply.dirX * dt->ply.plnY);
	dt->spr.dirX = (dt->ply.dirY * dt->spr.posX - dt->ply.dirX * dt->spr.posY);
	dt->spr.dirX *= invMatrix;
	dt->spr.dirY = (-dt->ply.plnY * dt->spr.posX + dt->ply.plnX * dt->spr.posY);
	dt->spr.dirY *= invMatrix;
}

static void	get_sprite_height(int *height, t_data *dt)
{
	(*height) = abs((int)(dt->screen_H / dt->spr.dirY));
	dt->spr.startY = dt->screen_H / 2 - (*height) / 2;
	if (dt->spr.startY < 0)
		dt->spr.startY = 0;
	dt->spr.endY = dt->screen_H / 2 + (*height) / 2;
	if (dt->spr.endY >= dt->screen_H)
		dt->spr.endY = dt->screen_H - 1;
}

static void	get_sprite_width(int *width, t_data *dt)
{
	(dt->spr.screenX)
		= (int)((dt->screen_W / 2) * (1 + dt->spr.dirX / dt->spr.dirY));
	(*width) = abs((int)(dt->screen_H / dt->spr.dirY));
	dt->spr.startX = (dt->spr.screenX) - (*width) / 2;
	if (dt->spr.startX < 0)
		dt->spr.startX = 0;
	dt->spr.endX = (dt->spr.screenX) + (*width) / 2;
	if (dt->spr.endX >= dt->screen_W)
		dt->spr.endX = dt->screen_W - 1;
}

void	cb_sprites(int **buffer, t_data *dt)
{
	int	y;
	int	height;
	int	width;

	get_sprites_dist(dt);
	y = 0;
	while (y < dt->spr.tot)
	{
		get_sprite_values(y, dt);
		get_sprite_height(&height, dt);
		get_sprite_width(&width, dt);
		cb_draw_sprites(width, height, buffer, dt);
		y++;
	}
}
