/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_findspr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:50:34 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 13:56:39 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_values(double *index, double *find)
{
	int	tmp;

	tmp = *index;
	*index = *find;
	*find = tmp;
}

static void	init_sprites(t_data *dt, t_map *map)
{
	int	y;
	int	x;
	int	z;

	y = 0;
	z = 0;
	while (y < map->y_axis)
	{
		x = 0;
		while (x < map->x_axis)
		{
			if (dt->map.world[y][x] == '2')
			{
				dt->spr.buf[z] = (double *)malloc(sizeof(double) * 2);
				dt->spr.buf[z][0] = y + 0.5;
				dt->spr.buf[z][1] = x + 0.5;
				z++;
			}
			x++;
		}
		y++;
	}
}

void	cb_find_sprites(t_data *dt, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	dt->spr.tot = 0;
	while (y < map->y_axis)
	{
		x = 0;
		while (x < map->x_axis)
		{
			if (dt->map.world[y][x] == '2')
				dt->spr.tot++;
			x++;
		}
		y++;
	}
	dt->spr.zbuf = (double *)malloc(sizeof(double) * dt->screen_W);
	dt->spr.dist = (double *)malloc(sizeof(double) * dt->spr.tot);
	dt->spr.buf = (double **)malloc(sizeof(double *) * dt->spr.tot);
	dt->spr.order = (double *)malloc(sizeof(double) * dt->spr.tot);
	init_sprites(dt, map);
}

void	cb_sort_sprites(double *order, double *dist, int tot)
{
	int		index;
	int		pos;
	int		find;
	double	men_dis;

	index = 0;
	while (index < tot)
	{
		pos = index + 1;
		find = index;
		men_dis = dist[index];
		while (pos < tot)
		{
			if (dist[pos] > men_dis)
				find = pos;
			if (dist[pos] > men_dis)
				men_dis = dist[pos];
			pos++;
		}
		if (men_dis != dist[index])
			swap_values(&order[index], &order[find]);
		if (men_dis != dist[index])
			swap_values(&dist[index], &dist[find]);
		index++;
	}
}
