/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_setdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:03:48 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 12:45:43 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_dir(t_data *dt)
{
	double	tmp;

	dt->ply.dirX = 0;
	dt->ply.dirY = -1;
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	dt->ply.plnX = 0.66;
	dt->ply.plnY = 0;
}

static void	set_south_dir(t_data *dt)
{
	double	tmp;

	dt->ply.dirX = 0;
	dt->ply.dirY = 1;
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	dt->ply.plnX = -0.66;
	dt->ply.plnY = 0;
}

static void	set_east_dir(t_data *dt)
{
	double	tmp;

	dt->ply.dirX = 1;
	dt->ply.dirY = 0;
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	dt->ply.plnX = 0;
	dt->ply.plnY = 0.66;
}

static void	set_west_dir(t_data *dt)
{
	double	tmp;

	dt->ply.dirX = -1;
	dt->ply.dirY = 0;
	tmp = dt->ply.dirX;
	dt->ply.lirX = dt->ply.dirY;
	dt->ply.lirY = -tmp;
	dt->ply.plnX = 0;
	dt->ply.plnY = -0.66;
}

void	cb_set_dir(char c, t_data *dt)
{
	if (c == 'N')
		set_north_dir(dt);
	else if (c == 'S')
		set_south_dir(dt);
	else if (c == 'W')
		set_west_dir(dt);
	else if (c == 'E')
		set_east_dir(dt);
}
