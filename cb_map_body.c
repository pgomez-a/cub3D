/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:15:08 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/13 08:40:24 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_map_space(int pos, int count_x, char **line, t_map *map)
{
	if ((map->matrix[pos][count_x - 1] != 'x'
		&& map->matrix[pos][count_x - 1] != '1')
		|| (map->matrix[pos - 1][count_x] != 'x'
		&& map->matrix[pos - 1][count_x] != '1'))
		ft_error("Error: Los espacios deben estar rodeados de muros\n");
	if ((*line)[count_x] == '1')
		map->matrix[pos][count_x] = '1';
}

void	cb_map_other(int pos, int count_x, char **line, t_map *map)
{
	if (map->matrix[pos][count_x - 1] == 'x'
			|| map->matrix[pos - 1][count_x] == 'x')
		ft_error("Error: Los espacios deben estar rodeados de muros\n");
	map->matrix[pos][count_x] = (*line)[count_x];
}

void	cb_map_x(int pos, int count_x, char **line, t_map *map)
{
	while (map->matrix[pos][count_x])
	{
		cb_map_space(pos, count_x, line, map);
		count_x++;
	}
}
