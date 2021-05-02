/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:35:45 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 12:47:06 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_key_press(int keycode, t_data *dt)
{
	if (keycode == 53)
	{
		ft_printf("\033[0;32mCub3D cerrado con exito :)\n\033[0m");
		ft_printf("\n\n");
		exit(0);
	}
	else if (keycode == 13)
		dt->key.mv_up = 1;
	else if (keycode == 1)
		dt->key.mv_down = 1;
	else if (keycode == 0)
		dt->key.mv_left = 1;
	else if (keycode == 2)
		dt->key.mv_right = 1;
	else if (keycode == 124)
		dt->key.rt_right = 1;
	else if (keycode == 123)
		dt->key.rt_left = 1;
	return (0);
}

int	cb_key_release(int keycode, t_data *dt)
{
	if (keycode == 13)
		dt->key.mv_up = 0;
	else if (keycode == 1)
		dt->key.mv_down = 0;
	else if (keycode == 0)
		dt->key.mv_left = 0;
	else if (keycode == 2)
		dt->key.mv_right = 0;
	else if (keycode == 124)
		dt->key.rt_right = 0;
	else if (keycode == 123)
		dt->key.rt_left = 0;
	return (0);
}
