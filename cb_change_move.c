/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:35:45 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 12:55:22 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_mv_up(double mv, t_data *dt)
{
	if (dt->map.world[(int)dt->ply.posY]
		[(int)(dt->ply.posX + dt->ply.dirX * mv)] == '0')
		dt->ply.posX += dt->ply.dirX * mv;
	if (dt->map.world[(int)(dt->ply.posY + dt->ply.dirY * mv)]
		[(int)dt->ply.posX] == '0')
		dt->ply.posY += dt->ply.dirY * mv;
}

void	cb_mv_down(double mv, t_data *dt)
{
	if (dt->map.world[(int)dt->ply.posY]
		[(int)(dt->ply.posX - dt->ply.dirX * mv)] == '0')
		dt->ply.posX -= dt->ply.dirX * mv;
	if (dt->map.world[(int)(dt->ply.posY - dt->ply.dirY * mv)]
		[(int)dt->ply.posX] == '0')
		dt->ply.posY -= dt->ply.dirY * mv;
}

void	cb_mv_left(double mv, t_data *dt)
{
	if (dt->map.world[(int)dt->ply.posY]
		[(int)(dt->ply.posX + dt->ply.lirX * mv)] == '0')
		dt->ply.posX += dt->ply.lirX * mv;
	if (dt->map.world[(int)(dt->ply.posY + dt->ply.lirY * mv)]
		[(int)dt->ply.posX] == '0')
		dt->ply.posY += dt->ply.lirY * mv;
}

void	cb_mv_right(double mv, t_data *dt)
{
	if (dt->map.world[(int)dt->ply.posY]
		[(int)(dt->ply.posX - dt->ply.lirX * mv)] == '0')
		dt->ply.posX -= dt->ply.lirX * mv;
	if (dt->map.world[(int)(dt->ply.posY - dt->ply.lirY * mv)]
		[(int)dt->ply.posX] == '0')
		dt->ply.posY -= dt->ply.lirY * mv;
}

void	cb_change_values(t_data *dt)
{
	double	mv_Speed;
	double	rot_Speed;

	mv_Speed = 0.1;
	rot_Speed = -0.05;
	if (dt->key.mv_up == 1)
		cb_mv_up(mv_Speed, dt);
	if (dt->key.mv_down == 1)
		cb_mv_down(mv_Speed, dt);
	if (dt->key.mv_left == 1)
		cb_mv_left(mv_Speed, dt);
	if (dt->key.mv_right == 1)
		cb_mv_right(mv_Speed, dt);
	if (dt->key.rt_right == 1)
		cb_rot_right(rot_Speed, dt);
	if (dt->key.rt_left == 1)
		cb_rot_left(rot_Speed, dt);
}
