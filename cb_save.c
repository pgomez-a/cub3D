/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:51:27 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/30 16:42:27 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_header(int fd, int size, t_data *dt)
{
	unsigned char	buffer[54];
	int				x;

	x = 0;
	while (x < 54)
		buffer[x++] = (unsigned char)0x00;
	buffer[0] = (unsigned char)0x42;
	buffer[1] = (unsigned char)0x4D;
	buffer[2] = (unsigned char)(size);
	buffer[3] = (unsigned char)(size >> 8);
	buffer[4] = (unsigned char)(size >> 16);
	buffer[5] = (unsigned char)(size >> 24);
	buffer[10] = (unsigned char)0x36;
	buffer[14] = (unsigned char)0x28;
	buffer[18] = (unsigned char)(dt->screen_W);
	buffer[19] = (unsigned char)(dt->screen_W >> 8);
	buffer[20] = (unsigned char)(dt->screen_W >> 16);
	buffer[21] = (unsigned char)(dt->screen_W >> 24);
	buffer[22] = (unsigned char)dt->screen_H;
	buffer[23] = (unsigned char)(dt->screen_H >> 8);
	buffer[24] = (unsigned char)(dt->screen_H >> 16);
	buffer[25] = (unsigned char)(dt->screen_H >> 24);
	buffer[26] = (unsigned char)0x01;
	buffer[28] = (unsigned char)0x20;
	write(fd, buffer, 54);
}

static void	put_color(int fd, int x, int y, t_data *dt)
{
	char			*color;
	unsigned char	tmp;

	color = dt->mlx.addr + (y * dt->mlx.length) + (x * (dt->mlx.bpp / 8));
	tmp = ((unsigned char)(*color) & 0x000000FF);
	write(fd, &tmp, 1);
	color = dt->mlx.addr + (y * dt->mlx.length) + (x * (dt->mlx.bpp / 8));
	color -= 3;
	tmp = ((unsigned char)(*color) & 0x000000FF);
	write(fd, &tmp, 1);
	color = dt->mlx.addr + (y * dt->mlx.length) + (x * (dt->mlx.bpp / 8));
	color -= 6;
	tmp = ((unsigned char)(*color) & 0x000000FF);
	write(fd, &tmp, 1);
	tmp = (unsigned char)0x00;
	write(fd, &tmp, 1);
}

void	cb_save(t_data *dt)
{
	int		fd;
	int		size;
	int		x;
	int		y;

	cb_render_frame(dt);
	size = 54 + (4 * dt->screen_W * dt->screen_H);
	fd = open("save.bmp", O_WRONLY | O_CREAT | O_APPEND, 0666);
	init_header(fd, size, dt);
	y = dt->screen_H - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < dt->screen_W)
			put_color(fd, x++, y, dt);
		y--;
	}
	close(fd);
	ft_printf("\033[0;36mCaptura completada!\n\033[0m");
	ft_printf("\n\n");
	exit(0);
}
