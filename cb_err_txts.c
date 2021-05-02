/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_err_txts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:19:32 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/12 14:22:36 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_err_north(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.no == 1)
		ft_error("Error: Texura Norte repetida\n");
	elems->rep.no = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 2;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Norte sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->north.path = ft_strdup(str);
	cb_look_path(elems->north.path);
	elems->north.path = str;
}

void	cb_err_south(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.so == 1)
		ft_error("Error: Textura Sur repetida\n");
	elems->rep.so = 1;
	count = 0;
	while (((*line)[count] == ' ' || (*line)[count] == '\t'))
		count++;
	count += 2;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Sur sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->south.path = ft_strdup(str);
	cb_look_path(elems->south.path);
	elems->south.path = str;
}

void	cb_err_west(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.we == 1)
		ft_error("Error: Textura Oeste repetida\n");
	elems->rep.we = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 2;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Oeste sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->west.path = ft_strdup(str);
	cb_look_path(elems->west.path);
	elems->west.path = str;
}

void	cb_err_east(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.ea == 1)
		ft_error("Error: Textura Este repetida\n");
	elems->rep.ea = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 2;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Este sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->east.path = ft_strdup(str);
	cb_look_path(elems->east.path);
	elems->east.path = str;
}

void	cb_err_sprite(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.sp == 1)
		ft_error("Error: Textura Sprite repetida\n");
	elems->rep.sp = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 1;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Sprite sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->sprite.path = ft_strdup(str);
	cb_look_path(elems->sprite.path);
	elems->sprite.path = str;
}
