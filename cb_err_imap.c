/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_err_imap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:19:05 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/13 08:39:45 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	elems_to_map(int fd, char **line)
{
	int		reads;

	reads = 1;
	while (reads == 1)
	{
		reads = get_next_line(fd, line);
		if (**line != '\0')
			break ;
		free(*line);
	}
}

static void	check_values(const char *str, t_map *map)
{
	char	*line;
	int		reads;
	int		fd;

	reads = 0;
	fd = open(str, O_RDONLY);
	while (reads < 8)
	{
		get_next_line(fd, &line);
		if (*line != '\0')
			reads++;
		free(line);
	}
	elems_to_map(fd, &line);
	map->player = 0;
	cb_map_first(&line, map);
	cb_map_body(fd, &line, map);
	if (map->player == 0)
		ft_error("Error: Falta jugador\n");
	cb_map_last(&line, map);
	close(fd);
}

void	cb_create_map(const char *str, t_map *map)
{
	int	count_y;
	int	count_x;

	count_y = 0;
	map->matrix = (char **)malloc(sizeof(char *) * (map->y_axis + 1));
	while (count_y < map->y_axis)
	{
		map->matrix[count_y] = (char *)malloc(sizeof(char) * (map->x_axis + 1));
		count_x = 0;
		while (count_x < map->x_axis)
			map->matrix[count_y][count_x++] = 'x';
		map->matrix[count_y][count_x] = '\0';
		count_y++;
	}
	check_values(str, map);
}
