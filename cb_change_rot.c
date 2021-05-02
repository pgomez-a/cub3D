/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_change_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:54 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 13:01:30 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_rot_right(double rot, t_data *dt)
{
	double	oldDirX;
	double	oldPlnX;
	double	tmp;

	oldDirX = dt->ply.dirX;
	dt->ply.dirX = dt->ply.dirX * cos(-rot) - dt->ply.dirY * sin(-rot);
	dt->ply.dirY = oldDirX * sin(-rot) + dt->ply.dirY * cos(-rot);
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	oldPlnX = dt->ply.plnX;
	dt->ply.plnX = dt->ply.plnX * cos(-rot) - dt->ply.plnY * sin(-rot);
	dt->ply.plnY = oldPlnX * sin (-rot) + dt->ply.plnY * cos(-rot);
}

void	cb_rot_left(double rot, t_data *dt)
{
	double	oldDirX;
	double	oldPlnX;
	double	tmp;

	oldDirX = dt->ply.dirX;
	dt->ply.dirX = dt->ply.dirX * cos(rot) - dt->ply.dirY * sin(rot);
	dt->ply.dirY = oldDirX * sin(rot) + dt->ply.dirY * cos(rot);
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	oldPlnX = dt->ply.plnX;
	dt->ply.plnX = dt->ply.plnX * cos(rot) - dt->ply.plnY * sin(rot);
	dt->ply.plnY = oldPlnX * sin (rot) + dt->ply.plnY * cos(rot);
}
