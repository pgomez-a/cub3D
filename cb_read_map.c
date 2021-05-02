/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:30:21 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/30 16:35:24 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_body_line(int pos, char **line, t_map *map)
{
	int	count_x;

	count_x = 1;
	while ((*line)[count_x])
	{
		if ((*line)[count_x] == '1')
			map->matrix[pos][count_x] = '1';
		else if ((*line)[count_x] == ' ')
			cb_map_space(pos, count_x, line, map);
		else
		{
			if ((*line)[count_x] != '0' && (*line)[count_x] != '2')
				map->player++;
			if (map->player > 1)
				ft_error("Error: Solo puede haber un jugador\n");
			cb_map_other(pos, count_x, line, map);
		}
		count_x++;
	}
	if ((*line)[count_x] == '\0' && count_x < map->x_axis)
		cb_map_x(pos, count_x, line, map);
}

static void	check_line(int pos, char **line, t_map *map)
{
	int	count_x;
	int	last;

	count_x = 0;
	if ((*line)[count_x] != '1' && (*line)[count_x] != ' '
		&& (*line)[count_x] != '\0')
		ft_error("Error: Mapa abierto\n");
	if ((*line)[count_x] == '1')
		map->matrix[pos][count_x] = '1';
	last = ft_strlen(*line) - 1;
	if ((*line)[last] != '1' && (*line)[last] != ' '
		&& (*line)[count_x] != '\0')
		ft_error("Error: Mapa abierto\n");
	check_body_line(pos, line, map);
}

void	cb_map_first(char **line, t_map *map)
{
	int	count_x;

	count_x = 0;
	while ((*line)[count_x] && map->matrix[0][count_x])
	{
		if ((*line)[count_x] != '1' && (*line)[count_x] != ' ')
			ft_error("Error: Mapa abierto\n");
		if ((*line)[count_x] == '1')
			map->matrix[0][count_x] = '1';
		count_x++;
	}
	free(*line);
}

void	cb_map_body(int fd, char **line, t_map *map)
{
	int	reads;
	int	pos;

	reads = 1;
	pos = 1;
	while (reads == 1)
	{
		reads = get_next_line(fd, line);
		if (pos == map->y_axis - 1)
			break ;
		check_line(pos, line, map);
		free(*line);
		pos++;
	}
}

void	cb_map_last(char **line, t_map *map)
{
	int	pos;
	int	count_x;

	pos = map->y_axis - 1;
	count_x = 0;
	while ((*line)[count_x] && map->matrix[pos][count_x])
	{
		if ((*line)[count_x] != '1' && (*line)[count_x] != ' ')
			ft_error("Error: Mapa abierto\n");
		count_x++;
	}
	check_line(pos, line, map);
	free(*line);
}
