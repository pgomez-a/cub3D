/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_err_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:19:19 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/13 11:34:30 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_values(int reads, char *str, t_map *map)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\t' || str[count] == '\n' || str[count] == '\f'
			|| str[count] == '\v' || str[count] == '\r')
			ft_error("Error: Solo se permite el espacio (ASCII 32)\n");
		if (reads == -1 || (str[count] != '0' && str[count] != '1'
				&& str[count] != '2' && str[count] != ' '
				&& str[count] != 'N' && str[count] != 'S'
				&& str[count] != 'E' && str[count] != 'W'))
			ft_error("Error: Mapa con valores no validos\n");
		if ((int)ft_strlen(str) > map->x_axis)
			map->x_axis = ft_strlen(str);
		count++;
	}
	map->y_axis++;
	return (reads);
}

static void	elems_to_map(int fd, t_map *map)
{
	char	*line;
	int		reads;

	reads = 1;
	map->x_axis = 0;
	map->y_axis = 0;
	while (reads == 1)
	{
		reads = get_next_line(fd, &line);
		if (*line != '\0')
			break ;
		if (reads == -1 || reads == 0)
			ft_error("Error: Falta descripcion mapa\n");
		free(line);
	}
	reads = check_map_values(reads, line, map);
	free(line);
}

void	cb_check_map(const char *str, t_map *map)
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
	elems_to_map(fd, map);
	reads = 1;
	while (reads == 1)
	{
		reads = get_next_line(fd, &line);
		reads = check_map_values(reads, line, map);
		free(line);
	}
	close(fd);
}
