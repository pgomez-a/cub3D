/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:35:27 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/30 16:38:51 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cb_exit(void)
{
	ft_printf("\033[0;32mCub3D cerrado con exito :)\n\033[0;32");
	ft_printf("\n");
	exit(0);
}

static void	find_player(t_data *dt, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y_axis)
	{
		x = 0;
		while (x < map->x_axis)
		{
			if (map->matrix[y][x] == 'N' || map->matrix[y][x] == 'S'
				|| map->matrix[y][x] == 'E' || map->matrix[y][x] == 'W')
			{
				cb_set_dir(map->matrix[y][x], dt);
				dt->ply.posX = (double)x + 0.2;
				dt->ply.posY = (double)y + 0.2;
				map->matrix[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

static void	init_values(t_data *dt, t_elem *elems, t_map *map)
{
	int	red;
	int	green;
	int	blue;

	dt->map.world = map->matrix;
	dt->screen_W = elems->res.x_axis;
	dt->screen_H = elems->res.y_axis;
	red = elems->color.cl_red << 16;
	green = elems->color.cl_green << 8;
	blue = elems->color.cl_blue;
	dt->map.ceil = red + green + blue;
	red = elems->color.fl_red << 16;
	green = elems->color.fl_green << 8;
	blue = elems->color.fl_blue;
	dt->map.floor = red + green + blue;
	dt->key.mv_up = 0;
	dt->key.mv_down = 0;
	dt->key.mv_right = 0;
	dt->key.mv_left = 0;
	dt->key.rt_left = 0;
	dt->key.rt_right = 0;
}

static void	init_textures(t_data *dt, t_elem *elems)
{
	dt->nor.path = ft_strtrim(elems->north.path, " \t");
	cb_north_texture(dt);
	dt->sou.path = ft_strtrim(elems->south.path, " \t");
	cb_south_texture(dt);
	dt->eas.path = ft_strtrim(elems->east.path, " \t");
	cb_east_texture(dt);
	dt->wes.path = ft_strtrim(elems->west.path, " \t");
	cb_west_texture(dt);
	dt->spr.path = ft_strtrim(elems->sprite.path, " \t");
	cb_sprite_texture(dt);
	dt->mlx.win
		= mlx_new_window(dt->mlx.mlx, dt->screen_W, dt->screen_H, "cub");
	dt->mlx.img = mlx_new_image(dt->mlx.mlx, dt->screen_W, dt->screen_H);
	dt->mlx.addr = mlx_get_data_addr(dt->mlx.img,
			&dt->mlx.bpp, &dt->mlx.length, &dt->mlx.end);
}

void	cb_cub(int verif, t_elem *elems, t_map *map)
{
	t_data	dt;
	int		size_x;
	int		size_y;

	dt.mlx.mlx = mlx_init();
	find_player(&dt, map);
	init_values(&dt, elems, map);
	init_textures(&dt, elems);
	cb_find_sprites(&dt, map);
	mlx_get_screen_size(dt.mlx.mlx, &size_x, &size_y);
	if (dt.screen_W > size_x)
		dt.screen_W = size_x;
	if (dt.screen_H > size_y)
		dt.screen_H = size_y;
	if (verif == 0)
		cb_save(&dt);
	mlx_hook(dt.mlx.win, 2, 0, cb_key_press, &dt);
	mlx_hook(dt.mlx.win, 3, 0, cb_key_release, &dt);
	mlx_hook(dt.mlx.win, 17, 0, cb_exit, &dt);
	mlx_loop_hook(dt.mlx.mlx, cb_render_frame, &dt);
	mlx_loop(dt.mlx.mlx);
}
